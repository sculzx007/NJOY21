struct Thnmax {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "thnmax"; }

  static std::string description(){
    return 
      "thnmax ia an optional argument specifies a (possible) maximum energy\n"
      "(in electron-volts) for broadening and thinning, which defaults to 1\n"
      "MeV when unspecified. thnmax is permitted to have both positive and\n"
      "negative values, where a negative value denotes special behavior.\n"
      "\n"
      "For positive values of thnmax, the actual upper limit of broadening and\n"
      "thinning operations is the minimum of:\n"
      " * the thnmax value\n"
      " * the end of the resolved resonance range\n"
      " * the minimum threshold energy among threshold reactions\n"
      " * 1.0 MeV\n"
      "\n"
      "For negative values of thnmax, the absolute value of the argument is\n"
      "used as the upper limit of broadening and thinning, regardless of other\n"
      "factors.\n"
      "\n"
      "Caution:\n"
      "Overriding the default behavior using a negative argument value will\n"
      "cause threshold reactions to be broadened. In legacy routines, this\n"
      "can cause the number of reactions to be broadened to excede an\n"
      "implementation limit (160 reactions).\n"
      "\n"
      "For use in transport codes, it is not recommended to override the\n"
      "default behavior. The spectrum of scattered neutrons is not broadened\n"
      "by NJOY";
  }

  static Value_t defaultValue(){ return 1.0 * mega(electronVolts); }
};
