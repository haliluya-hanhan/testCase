//check type:cpp
//Language:CPP
class class_s_37_03_OVERLOAD_ASSIGN_NONSTANDARD_medium_01_bad{
    public:
      int a;
      void & operator = (const class_s_37_03_OVERLOAD_ASSIGN_NONSTANDARD_medium_01_bad & rhs);  //not compliant
};



class class_s_37_03_OVERLOAD_ASSIGN_NONSTANDARD_medium_01_good{
    public:
      int a;
      class_s_37_03_OVERLOAD_ASSIGN_NONSTANDARD_medium_01_good& operator = (const class_s_37_03_OVERLOAD_ASSIGN_NONSTANDARD_medium_01_good & rhs);

};

