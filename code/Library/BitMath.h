#ifndef BITMATH_H_
#define BITMATH_H_
#define SetBit(Reg,BitNo) (Reg |=(1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~(1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^=(1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)


#define SET_BIT(_REG,PIN)      (_REG=_REG | (MASK_PIN <<PIN))
#define CLEAR_BIT(_REG,PIN)    (_REG=_REG & (~(MASK_PIN<<PIN)))
#define TOGGLE_BIT(_REG,PIN)   (_REG=_REG ^ (MASK_PIN<<PIN))
#define READ_BIT(_REG,PIN)     ((_REG>>PIN)  & MASK_PIN)
//#define GetBit(Reg,BitNo) ((Reg& (1<<BitNo))>>BitNo)
#endif /* BITMATH_H_ */
