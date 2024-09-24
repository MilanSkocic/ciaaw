module ciaaw__saw
    !! Ciaaw saw - Autogenerated
    !! See [specs](../page/specs/ciaaw_saw.html)
    use ciaaw__common
    use ciaaw__types
    private

type(saw_type), parameter, public :: H_saw = &
saw_type(1.00784_dp, 1.00811_dp, nan_dp, nan_dp, &
1.0080_dp, 0.0002_dp) !! H

type(saw_type), parameter, public :: He_saw = &
saw_type(nan_dp, nan_dp, 4.002602_dp, 0.000002_dp, &
4.0026_dp, 0.0001_dp) !! He

type(saw_type), parameter, public :: Li_saw = &
saw_type(6.938_dp, 6.997_dp, nan_dp, nan_dp, &
6.94_dp, 0.06_dp) !! Li

type(saw_type), parameter, public :: Be_saw = &
saw_type(nan_dp, nan_dp, 9.0121831_dp, 0.0000005_dp, &
9.0122_dp, 0.00001_dp) !! Be

type(saw_type), parameter, public :: B_saw = &
saw_type(10.806_dp, 10.821_dp, nan_dp, nan_dp, &
10.81_dp, 0.02_dp) !! B

type(saw_type), parameter, public :: C_saw = &
saw_type(12.0096_dp, 12.0116_dp, nan_dp, nan_dp, &
12.011_dp, 0.002_dp) !! C

type(saw_type), parameter, public :: N_saw = &
saw_type(14.00643_dp, 14.00728_dp, nan_dp, nan_dp, &
14.007_dp, 0.001_dp) !! N

type(saw_type), parameter, public :: O_saw = &
saw_type(15.99903_dp, 15.99977_dp, nan_dp, nan_dp, &
15.999_dp, 0.001_dp) !! O

type(saw_type), parameter, public :: F_saw = &
saw_type(nan_dp, nan_dp, 18.998403162_dp, 0.000000005_dp, &
18.998_dp, 0.001_dp) !! F

type(saw_type), parameter, public :: Ne_saw = &
saw_type(nan_dp, nan_dp, 20.1797_dp, 0.0006_dp, &
20.180_dp, 0.001_dp) !! Ne

type(saw_type), parameter, public :: Na_saw = &
saw_type(nan_dp, nan_dp, 22.98976928_dp, 0.00000002_dp, &
22.990_dp, 0.001_dp) !! Na

type(saw_type), parameter, public :: Mg_saw = &
saw_type(24.304_dp, 24.307_dp, nan_dp, nan_dp, &
24.305_dp, 0.002_dp) !! Mg

type(saw_type), parameter, public :: Al_saw = &
saw_type(nan_dp, nan_dp, 26.9815384_dp, 0.0000003_dp, &
26.982_dp, 0.001_dp) !! Al

type(saw_type), parameter, public :: Si_saw = &
saw_type(28.084_dp, 28.086_dp, nan_dp, nan_dp, &
28.085_dp, 0.001_dp) !! Si

type(saw_type), parameter, public :: P_saw = &
saw_type(nan_dp, nan_dp, 30.973761998_dp, 0.000000005_dp, &
30.974_dp, 0.001_dp) !! P

type(saw_type), parameter, public :: S_saw = &
saw_type(32.059_dp, 32.076_dp, nan_dp, nan_dp, &
32.06_dp, 0.02_dp) !! S

type(saw_type), parameter, public :: Cl_saw = &
saw_type(35.446_dp, 35.457_dp, nan_dp, nan_dp, &
35.45_dp, 0.01_dp) !! Cl

type(saw_type), parameter, public :: Ar_saw = &
saw_type(39.792_dp, 39.963_dp, nan_dp, nan_dp, &
39.95_dp, 0.16_dp) !! Ar

type(saw_type), parameter, public :: K_saw = &
saw_type(nan_dp, nan_dp, 39.0983_dp, 0.0001_dp, &
39.098_dp, 0.001_dp) !! K

type(saw_type), parameter, public :: Ca_saw = &
saw_type(nan_dp, nan_dp, 40.078_dp, 0.004_dp, &
40.078_dp, 0.004_dp) !! Ca

type(saw_type), parameter, public :: Sc_saw = &
saw_type(nan_dp, nan_dp, 44.955907_dp, 0.000004_dp, &
44.956_dp, 0.001_dp) !! Sc

type(saw_type), parameter, public :: Ti_saw = &
saw_type(nan_dp, nan_dp, 47.867_dp, 0.001_dp, &
47.867_dp, 0.001_dp) !! Ti

type(saw_type), parameter, public :: V_saw = &
saw_type(nan_dp, nan_dp, 50.9415_dp, 0.0001_dp, &
50.942_dp, 0.001_dp) !! V

type(saw_type), parameter, public :: Cr_saw = &
saw_type(nan_dp, nan_dp, 51.9961_dp, 0.0006_dp, &
51.996_dp, 0.001_dp) !! Cr

type(saw_type), parameter, public :: Mn_saw = &
saw_type(nan_dp, nan_dp, 54.938043_dp, 0.000002_dp, &
54.938_dp, 0.001_dp) !! Mn

type(saw_type), parameter, public :: Fe_saw = &
saw_type(nan_dp, nan_dp, 55.845_dp, 0.002_dp, &
55.845_dp, 0.002_dp) !! Fe

type(saw_type), parameter, public :: Co_saw = &
saw_type(nan_dp, nan_dp, 58.933194_dp, 0.000003_dp, &
58.933_dp, 0.001_dp) !! Co

type(saw_type), parameter, public :: Ni_saw = &
saw_type(nan_dp, nan_dp, 58.6934_dp, 0.0004_dp, &
58.693_dp, 0.001_dp) !! Ni

type(saw_type), parameter, public :: Cu_saw = &
saw_type(nan_dp, nan_dp, 63.546_dp, 0.003_dp, &
63.546_dp, 0.003_dp) !! Cu

type(saw_type), parameter, public :: Zn_saw = &
saw_type(nan_dp, nan_dp, 65.38_dp, 0.02_dp, &
65.38_dp, 0.02_dp) !! Zn

type(saw_type), parameter, public :: Ga_saw = &
saw_type(nan_dp, nan_dp, 69.723_dp, 0.001_dp, &
69.723_dp, 0.001_dp) !! Ga

type(saw_type), parameter, public :: Ge_saw = &
saw_type(nan_dp, nan_dp, 72.630_dp, 0.008_dp, &
72.630_dp, 0.008_dp) !! Ge

type(saw_type), parameter, public :: As_saw = &
saw_type(nan_dp, nan_dp, 74.921595_dp, 0.000006_dp, &
74.922_dp, 0.001_dp) !! As

type(saw_type), parameter, public :: Se_saw = &
saw_type(nan_dp, nan_dp, 78.971_dp, 0.008_dp, &
78.971_dp, 0.008_dp) !! Se

type(saw_type), parameter, public :: Br_saw = &
saw_type(79.901_dp, 79.907_dp, nan_dp, nan_dp, &
79.904_dp, 0.003_dp) !! Br

type(saw_type), parameter, public :: Kr_saw = &
saw_type(nan_dp, nan_dp, 83.798_dp, 0.002_dp, &
83.798_dp, 0.002_dp) !! Kr

type(saw_type), parameter, public :: Rb_saw = &
saw_type(nan_dp, nan_dp, 85.4678_dp, 0.0003_dp, &
85.468_dp, 0.001_dp) !! Rb

type(saw_type), parameter, public :: Sr_saw = &
saw_type(nan_dp, nan_dp, 87.62_dp, 0.01_dp, &
87.62_dp, 0.01_dp) !! Sr

type(saw_type), parameter, public :: Y_saw = &
saw_type(nan_dp, nan_dp, 88.905838_dp, 0.000002_dp, &
88.906_dp, 0.001_dp) !! Y

type(saw_type), parameter, public :: Zr_saw = &
saw_type(nan_dp, nan_dp, 91.224_dp, 0.002_dp, &
91.224_dp, 0.002_dp) !! Zr

type(saw_type), parameter, public :: Nb_saw = &
saw_type(nan_dp, nan_dp, 92.90637_dp, 0.00001_dp, &
92.906_dp, 0.001_dp) !! Nb

type(saw_type), parameter, public :: Mo_saw = &
saw_type(nan_dp, nan_dp, 95.95_dp, 0.01_dp, &
95.95_dp, 0.01_dp) !! Mo

type(saw_type), parameter, public :: Tc_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Tc

type(saw_type), parameter, public :: Ru_saw = &
saw_type(nan_dp, nan_dp, 101.07_dp, 0.02_dp, &
101.07_dp, 0.02_dp) !! Ru

type(saw_type), parameter, public :: Rh_saw = &
saw_type(nan_dp, nan_dp, 102.90549_dp, 0.00002_dp, &
102.91_dp, 0.01_dp) !! Rh

type(saw_type), parameter, public :: Pd_saw = &
saw_type(nan_dp, nan_dp, 106.42_dp, 0.01_dp, &
106.42_dp, 0.01_dp) !! Pd

type(saw_type), parameter, public :: Ag_saw = &
saw_type(nan_dp, nan_dp, 107.8682_dp, 0.0002_dp, &
107.87_dp, 0.01_dp) !! Ag

type(saw_type), parameter, public :: Cd_saw = &
saw_type(nan_dp, nan_dp, 112.414_dp, 0.004_dp, &
112.41_dp, 0.01_dp) !! Cd

type(saw_type), parameter, public :: In_saw = &
saw_type(nan_dp, nan_dp, 114.818_dp, 0.001_dp, &
114.82_dp, 0.01_dp) !! In

type(saw_type), parameter, public :: Sn_saw = &
saw_type(nan_dp, nan_dp, 118.70_dp, 0.007_dp, &
118.71_dp, 0.01_dp) !! Sn

type(saw_type), parameter, public :: Sb_saw = &
saw_type(nan_dp, nan_dp, 121.760_dp, 0.001_dp, &
121.76_dp, 0.01_dp) !! Sb

type(saw_type), parameter, public :: Te_saw = &
saw_type(nan_dp, nan_dp, 127.60_dp, 0.03_dp, &
127.60_dp, 0.03_dp) !! Te

type(saw_type), parameter, public :: I_saw = &
saw_type(nan_dp, nan_dp, 126.90447_dp, 0.00003_dp, &
126.90_dp, 0.01_dp) !! I

type(saw_type), parameter, public :: Xe_saw = &
saw_type(nan_dp, nan_dp, 131.293_dp, 0.006_dp, &
131.29_dp, 0.01_dp) !! Xe

type(saw_type), parameter, public :: Cs_saw = &
saw_type(nan_dp, nan_dp, 132.90545196_dp, 0.00000006_dp, &
132.91_dp, 0.01_dp) !! Cs

type(saw_type), parameter, public :: Ba_saw = &
saw_type(nan_dp, nan_dp, 137.327_dp, 0.007_dp, &
137.33_dp, 0.01_dp) !! Ba

type(saw_type), parameter, public :: La_saw = &
saw_type(nan_dp, nan_dp, 138.90547_dp, 0.00007_dp, &
138.91_dp, 0.01_dp) !! La

type(saw_type), parameter, public :: Ce_saw = &
saw_type(nan_dp, nan_dp, 140.116_dp, 0.001_dp, &
140.12_dp, 0.01_dp) !! Ce

type(saw_type), parameter, public :: Pr_saw = &
saw_type(nan_dp, nan_dp, 140.90766_dp, 0.00001_dp, &
140.91_dp, 0.01_dp) !! Pr

type(saw_type), parameter, public :: Nd_saw = &
saw_type(nan_dp, nan_dp, 144.242_dp, 0.003_dp, &
144.24_dp, 0.01_dp) !! Nd

type(saw_type), parameter, public :: Pm_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Pm

type(saw_type), parameter, public :: Sm_saw = &
saw_type(nan_dp, nan_dp, 150.36_dp, 0.02_dp, &
150.36_dp, 0.02_dp) !! Sm

type(saw_type), parameter, public :: Eu_saw = &
saw_type(nan_dp, nan_dp, 151.964_dp, 0.001_dp, &
151.96_dp, 0.01_dp) !! Eu

type(saw_type), parameter, public :: Gd_saw = &
saw_type(nan_dp, nan_dp, 157.25_dp, 0.03_dp, &
157.25_dp, 0.03_dp) !! Gd

type(saw_type), parameter, public :: Tb_saw = &
saw_type(nan_dp, nan_dp, 158.925354_dp, 0.000007_dp, &
158.93_dp, 0.01_dp) !! Tb

type(saw_type), parameter, public :: Dy_saw = &
saw_type(nan_dp, nan_dp, 162.500_dp, 0.001_dp, &
162.50_dp, 0.01_dp) !! Dy

type(saw_type), parameter, public :: Ho_saw = &
saw_type(nan_dp, nan_dp, 164.930329_dp, 0.000005_dp, &
164.93_dp, 0.01_dp) !! Ho

type(saw_type), parameter, public :: Er_saw = &
saw_type(nan_dp, nan_dp, 167.259_dp, 0.003_dp, &
167.26_dp, 0.01_dp) !! Er

type(saw_type), parameter, public :: Tm_saw = &
saw_type(nan_dp, nan_dp, 168.934219_dp, 0.000005_dp, &
168.93_dp, 0.01_dp) !! Tm

type(saw_type), parameter, public :: Yb_saw = &
saw_type(nan_dp, nan_dp, 173.045_dp, 0.010_dp, &
173.05_dp, 0.02_dp) !! Yb

type(saw_type), parameter, public :: Lu_saw = &
saw_type(nan_dp, nan_dp, 174.9668_dp, 0.0001_dp, &
174.97_dp, 0.01_dp) !! Lu

type(saw_type), parameter, public :: Hf_saw = &
saw_type(nan_dp, nan_dp, 178.486_dp, 0.006_dp, &
178.49_dp, 0.01_dp) !! Hf

type(saw_type), parameter, public :: Ta_saw = &
saw_type(nan_dp, nan_dp, 180.94788_dp, 0.00002_dp, &
180.95_dp, 0.01_dp) !! Ta

type(saw_type), parameter, public :: W_saw = &
saw_type(nan_dp, nan_dp, 183.84_dp, 0.01_dp, &
183.84_dp, 0.01_dp) !! W

type(saw_type), parameter, public :: Re_saw = &
saw_type(nan_dp, nan_dp, 186.207_dp, 0.001_dp, &
186.21_dp, 0.01_dp) !! Re

type(saw_type), parameter, public :: Os_saw = &
saw_type(nan_dp, nan_dp, 190.23_dp, 0.03_dp, &
190.23_dp, 0.03_dp) !! Os

type(saw_type), parameter, public :: Ir_saw = &
saw_type(nan_dp, nan_dp, 192.217_dp, 0.002_dp, &
192.22_dp, 0.01_dp) !! Ir

type(saw_type), parameter, public :: Pt_saw = &
saw_type(nan_dp, nan_dp, 195.084_dp, 0.009_dp, &
195.08_dp, 0.02_dp) !! Pt

type(saw_type), parameter, public :: Au_saw = &
saw_type(nan_dp, nan_dp, 196.966570_dp, 0.000004_dp, &
196.97_dp, 0.01_dp) !! Au

type(saw_type), parameter, public :: Hg_saw = &
saw_type(nan_dp, nan_dp, 200.592_dp, 0.003_dp, &
200.59_dp, 0.01_dp) !! Hg

type(saw_type), parameter, public :: Tl_saw = &
saw_type(204.382_dp, 204.385_dp, nan_dp, nan_dp, &
204.38_dp, 0.01_dp) !! Tl

type(saw_type), parameter, public :: Pb_saw = &
saw_type(206.14_dp, 207.94_dp, nan_dp, nan_dp, &
207.2_dp, 1.1_dp) !! Pb

type(saw_type), parameter, public :: Bi_saw = &
saw_type(nan_dp, nan_dp, 208.98040_dp, 0.00001_dp, &
208.98_dp, 0.01_dp) !! Bi

type(saw_type), parameter, public :: Po_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Po

type(saw_type), parameter, public :: At_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! At

type(saw_type), parameter, public :: Rn_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Rn

type(saw_type), parameter, public :: Fr_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Fr

type(saw_type), parameter, public :: Ra_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Ra

type(saw_type), parameter, public :: Ac_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Ac

type(saw_type), parameter, public :: Th_saw = &
saw_type(nan_dp, nan_dp, 232.0377_dp, 0.0004_dp, &
232.04_dp, 0.01_dp) !! Th

type(saw_type), parameter, public :: Pa_saw = &
saw_type(nan_dp, nan_dp, 231.03588_dp, 0.00001_dp, &
231.04_dp, 0.01_dp) !! Pa

type(saw_type), parameter, public :: U_saw = &
saw_type(nan_dp, nan_dp, 238.02891_dp, 0.00003_dp, &
238.03_dp, 0.01_dp) !! U

type(saw_type), parameter, public :: Np_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Np

type(saw_type), parameter, public :: Pu_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Pu

type(saw_type), parameter, public :: Am_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Am

type(saw_type), parameter, public :: Cm_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Cm

type(saw_type), parameter, public :: Bk_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Bk

type(saw_type), parameter, public :: Cf_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Cf

type(saw_type), parameter, public :: Es_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Es

type(saw_type), parameter, public :: Fm_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Fm

type(saw_type), parameter, public :: Md_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Md

type(saw_type), parameter, public :: No_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! No

type(saw_type), parameter, public :: Lr_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Lr

type(saw_type), parameter, public :: Rf_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Rf

type(saw_type), parameter, public :: Db_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Db

type(saw_type), parameter, public :: Sg_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Sg

type(saw_type), parameter, public :: Bh_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Bh

type(saw_type), parameter, public :: Hs_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Hs

type(saw_type), parameter, public :: Mt_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Mt

type(saw_type), parameter, public :: Ds_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Ds

type(saw_type), parameter, public :: Rg_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Rg

type(saw_type), parameter, public :: Cn_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Cn

type(saw_type), parameter, public :: Nh_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Nh

type(saw_type), parameter, public :: Fl_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Fl

type(saw_type), parameter, public :: Mc_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Mc

type(saw_type), parameter, public :: Lv_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Lv

type(saw_type), parameter, public :: Ts_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Ts

type(saw_type), parameter, public :: Og_saw = &
saw_type(nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp) !! Og

end module ciaaw__saw
