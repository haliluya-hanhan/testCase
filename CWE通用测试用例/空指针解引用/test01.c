//check type:c/cpp
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
	GLIST_SORT_ALPHA,
	GLIST_SORT_FILE_ALPHA,
	GLIST_SORT_VALUE,
	GLIST_SORT_NONE
} e_glist_sort;
struct generic_node {
	char name[1024];
	unsigned long  value;
	unsigned long  data;
	struct generic_node *next;
};
int num_items = 0;
e_glist_sort sort_method = GLIST_SORT_ALPHA;
void addElement ( char *name, int value, int data ,struct generic_node *element) {

		struct generic_node *tmp_item;
		struct generic_node *prev_item;
		char current_name[1024];
		char new_name[1024];
		int i;
		int done_flag = 0;

		num_items++;

		/*
		 * Add Element to List
		 */
		if ( tmp_item = element ) {

			switch ( sort_method ) {

				case GLIST_SORT_ALPHA:
				case GLIST_SORT_FILE_ALPHA:

				i = -1;
				while ( name[++i] )
					new_name[i] = tolower ( name[i] );
				new_name[i] = '\0';

				prev_item = 0;
				while ( tmp_item ) {

					i = -1;
					while ( tmp_item->name[++i] )
						current_name[i] = tolower ( tmp_item->name[i] );
					current_name[i] = '\0';

					/*
					 * Sort directories first, then alphabetical for Files
					 *    Or just plain old sort alphabetical
					 */
					if ( (value==1 && tmp_item->value==0 &&
					      sort_method==GLIST_SORT_FILE_ALPHA) ||
					     ((strcmp(new_name,current_name) < 0) && value==tmp_item->value) ) {

						if ( prev_item ) {
							prev_item->next = (struct generic_node *)malloc ( sizeof(struct generic_node) );
							prev_item->next->next = tmp_item;  //not compliant
							tmp_item = prev_item->next;
						}
						else {
							element = (struct generic_node *)malloc ( sizeof(struct generic_node) );
							element->next = tmp_item;
							tmp_item = element;
						}
						done_flag = 1;
						break;
					}

					prev_item = tmp_item;
					tmp_item = tmp_item->next;
				}
				if ( !done_flag ) {
					if ( !prev_item )
						prev_item = element;
					prev_item->next = (struct generic_node *)malloc ( sizeof(struct generic_node) );
					tmp_item = prev_item->next;
					tmp_item->next = 0;     //not compliant
				}
				break;

				case GLIST_SORT_VALUE:
					prev_item = 0;
					while ( tmp_item->next ) {
						if ( tmp_item->value < (unsigned int)value ) {
						}
						tmp_item = tmp_item->next;
					}
				break;

				case GLIST_SORT_NONE:
					while ( tmp_item->next ) {
						tmp_item = tmp_item->next;
					}
					tmp_item->next = (struct generic_node *)malloc ( sizeof(struct generic_node) );  //compliant
					tmp_item = tmp_item->next;
					tmp_item->next = 0;
					break;

			} /* end switch sort method */

		} /* end if list elements exist */

		/*
		 * Or Create List
		 */
		else {
			element = (struct generic_node *)malloc ( sizeof(struct generic_node) );
			tmp_item = element;
			tmp_item->next = 0; //not compliant
		}

		strcpy ( tmp_item->name, name );
		tmp_item->value = value;
		tmp_item->data = data;
	}
