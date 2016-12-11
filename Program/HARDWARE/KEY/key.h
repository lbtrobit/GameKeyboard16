# ifndef __KEY_H
# define __KEY_H
# include "sys.h"
# define h1 PAin(7)
# define h2 PAin(6)
# define h3 PAin(5)
# define h4 PAin(4)
# define h5 PBin(15)
# define h6 PBin(14)
# define h7 PBin(13)
# define h8 PBin(12)
# define K1_PRES 0X00000001
# define K2_PRES 0X00000002
# define K3_PRES 0X00000004
# define K4_PRES 0X00000008
# define KQ_PRES 0X00000010
# define KW_PRES 0X00000020
# define KE_PRES 0X00000040
# define KR_PRES 0X00000080
# define KA_PRES 0X00000100
# define KS_PRES 0X00000200
# define KD_PRES 0X00000400
# define KF_PRES 0X00000800
# define K5_PRES 0X00001000
# define KZ_PRES 0X00002000
# define KX_PRES 0X00004000
# define KSP_PRES 0X00008000
# define KP_PRES 0X00010000
# define KL_PRES 0X00100000
# define KM_PRES 0X01000000
# define KY_PRES 0X10000000
# define KO_PRES 0X00020000
# define KK_PRES 0X00200000
# define KN_PRES 0X02000000
# define KDO_PRES 0X20000000
# define KI_PRES 0X00040000
# define KJ_PRES 0X00400000
# define KB_PRES 0X04000000
# define KBS_PRES 0X40000000
# define KU_PRES 0X00080000
# define KH_PRES 0X00800000
# define KG_PRES 0X08000000
# define KEN_PRES 0X80000000
void Key_Init(void);
u32 Key_Scan(void);
#endif

