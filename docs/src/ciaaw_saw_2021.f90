module ciaaw__saw_2021
    !! Ciaaw saw - Autogenerated
    use stdlib_kinds, only: dp, int32, int64
    use ciaaw__saw_type
    private
    integer(int64), parameter :: x = 1
    real(dp), parameter :: nan_dp = transfer(huge(x), 1.0_dp)

integer(int32), parameter, public :: YEAR = 2021 !! Year of release.

type(saw_type), parameter, public :: H = &
saw_type("hydrogen", "H", 1, &
1.00784_dp, 1.00811_dp, 1.00798_dp, 8e-05_dp, &
1.0080_dp, 0.0002_dp, "m") !! hydrogen

type(saw_type), parameter, public :: He = &
saw_type("helium", "He", 2, &
nan_dp, nan_dp, 4.002602_dp, 0.000002_dp, &
4.0026_dp, 0.0001_dp, "g r") !! helium

type(saw_type), parameter, public :: Li = &
saw_type("lithium", "Li", 3, &
6.938_dp, 6.997_dp, 6.97_dp, 0.02_dp, &
6.94_dp, 0.06_dp, "m") !! lithium

type(saw_type), parameter, public :: Be = &
saw_type("beryllium", "Be", 4, &
nan_dp, nan_dp, 9.0121831_dp, 0.0000005_dp, &
9.0122_dp, 0.00001_dp, "") !! beryllium

type(saw_type), parameter, public :: B = &
saw_type("boron", "B", 5, &
10.806_dp, 10.821_dp, 10.813_dp, 0.005_dp, &
10.81_dp, 0.02_dp, "m") !! boron

type(saw_type), parameter, public :: C = &
saw_type("carbon", "C", 6, &
12.0096_dp, 12.0116_dp, 12.0106_dp, 0.0006_dp, &
12.011_dp, 0.002_dp, "m") !! carbon

type(saw_type), parameter, public :: N = &
saw_type("nitrogen", "N", 7, &
14.00643_dp, 14.00728_dp, 14.0069_dp, 0.0003_dp, &
14.007_dp, 0.001_dp, "m") !! nitrogen

type(saw_type), parameter, public :: O = &
saw_type("oxygen", "O", 8, &
15.99903_dp, 15.99977_dp, 15.9994_dp, 0.0003_dp, &
15.999_dp, 0.001_dp, "m") !! oxygen

type(saw_type), parameter, public :: F = &
saw_type("fluorine", "F", 9, &
nan_dp, nan_dp, 18.998403162_dp, 0.000000005_dp, &
18.998_dp, 0.001_dp, "") !! fluorine

type(saw_type), parameter, public :: Ne = &
saw_type("neon", "Ne", 10, &
nan_dp, nan_dp, 20.1797_dp, 0.0006_dp, &
20.180_dp, 0.001_dp, "g m") !! neon

type(saw_type), parameter, public :: Na = &
saw_type("sodium", "Na", 11, &
nan_dp, nan_dp, 22.98976928_dp, 0.00000002_dp, &
22.990_dp, 0.001_dp, "") !! sodium

type(saw_type), parameter, public :: Mg = &
saw_type("magnesium", "Mg", 12, &
24.304_dp, 24.307_dp, 24.3055_dp, 0.0009_dp, &
24.305_dp, 0.002_dp, "") !! magnesium

type(saw_type), parameter, public :: Al = &
saw_type("aluminium", "Al", 13, &
nan_dp, nan_dp, 26.9815384_dp, 0.0000003_dp, &
26.982_dp, 0.001_dp, "") !! aluminium

type(saw_type), parameter, public :: Si = &
saw_type("silicon", "Si", 14, &
28.084_dp, 28.086_dp, 28.085_dp, 0.0006_dp, &
28.085_dp, 0.001_dp, "") !! silicon

type(saw_type), parameter, public :: P = &
saw_type("phosphorus", "P", 15, &
nan_dp, nan_dp, 30.973761998_dp, 0.000000005_dp, &
30.974_dp, 0.001_dp, "") !! phosphorus

type(saw_type), parameter, public :: S = &
saw_type("sulfur", "S", 16, &
32.059_dp, 32.076_dp, 32.067_dp, 0.005_dp, &
32.06_dp, 0.02_dp, "") !! sulfur

type(saw_type), parameter, public :: Cl = &
saw_type("chlorine", "Cl", 17, &
35.446_dp, 35.457_dp, 35.451_dp, 0.004_dp, &
35.45_dp, 0.01_dp, "m") !! chlorine

type(saw_type), parameter, public :: Ar = &
saw_type("argon", "Ar", 18, &
39.792_dp, 39.963_dp, 39.88_dp, 0.05_dp, &
39.95_dp, 0.16_dp, "") !! argon

type(saw_type), parameter, public :: K = &
saw_type("potassium", "K", 19, &
nan_dp, nan_dp, 39.0983_dp, 0.0001_dp, &
39.098_dp, 0.001_dp, "") !! potassium

type(saw_type), parameter, public :: Ca = &
saw_type("calcium", "Ca", 20, &
nan_dp, nan_dp, 40.078_dp, 0.004_dp, &
40.078_dp, 0.004_dp, "g") !! calcium

type(saw_type), parameter, public :: Sc = &
saw_type("scandium", "Sc", 21, &
nan_dp, nan_dp, 44.955907_dp, 0.000004_dp, &
44.956_dp, 0.001_dp, "") !! scandium

type(saw_type), parameter, public :: Ti = &
saw_type("titanium", "Ti", 22, &
nan_dp, nan_dp, 47.867_dp, 0.001_dp, &
47.867_dp, 0.001_dp, "") !! titanium

type(saw_type), parameter, public :: V = &
saw_type("vanadium", "V", 23, &
nan_dp, nan_dp, 50.9415_dp, 0.0001_dp, &
50.942_dp, 0.001_dp, "") !! vanadium

type(saw_type), parameter, public :: Cr = &
saw_type("chromium", "Cr", 24, &
nan_dp, nan_dp, 51.9961_dp, 0.0006_dp, &
51.996_dp, 0.001_dp, "") !! chromium

type(saw_type), parameter, public :: Mn = &
saw_type("manganese", "Mn", 25, &
nan_dp, nan_dp, 54.938043_dp, 0.000002_dp, &
54.938_dp, 0.001_dp, "") !! manganese

type(saw_type), parameter, public :: Fe = &
saw_type("iron", "Fe", 26, &
nan_dp, nan_dp, 55.845_dp, 0.002_dp, &
55.845_dp, 0.002_dp, "") !! iron

type(saw_type), parameter, public :: Co = &
saw_type("cobalt", "Co", 27, &
nan_dp, nan_dp, 58.933194_dp, 0.000003_dp, &
58.933_dp, 0.001_dp, "") !! cobalt

type(saw_type), parameter, public :: Ni = &
saw_type("nickel", "Ni", 28, &
nan_dp, nan_dp, 58.6934_dp, 0.0004_dp, &
58.693_dp, 0.001_dp, "r") !! nickel

type(saw_type), parameter, public :: Cu = &
saw_type("copper", "Cu", 29, &
nan_dp, nan_dp, 63.546_dp, 0.003_dp, &
63.546_dp, 0.003_dp, "r") !! copper

type(saw_type), parameter, public :: Zn = &
saw_type("zinc", "Zn", 30, &
nan_dp, nan_dp, 65.38_dp, 0.02_dp, &
65.38_dp, 0.02_dp, "r") !! zinc

type(saw_type), parameter, public :: Ga = &
saw_type("gallium", "Ga", 31, &
nan_dp, nan_dp, 69.723_dp, 0.001_dp, &
69.723_dp, 0.001_dp, "") !! gallium

type(saw_type), parameter, public :: Ge = &
saw_type("germanium", "Ge", 32, &
nan_dp, nan_dp, 72.630_dp, 0.008_dp, &
72.630_dp, 0.008_dp, "") !! germanium

type(saw_type), parameter, public :: As = &
saw_type("arsenic", "As", 33, &
nan_dp, nan_dp, 74.921595_dp, 0.000006_dp, &
74.922_dp, 0.001_dp, "r") !! arsenic

type(saw_type), parameter, public :: Se = &
saw_type("selenium", "Se", 34, &
nan_dp, nan_dp, 78.971_dp, 0.008_dp, &
78.971_dp, 0.008_dp, "") !! selenium

type(saw_type), parameter, public :: Br = &
saw_type("bromine", "Br", 35, &
79.901_dp, 79.907_dp, 79.904_dp, 0.002_dp, &
79.904_dp, 0.003_dp, "") !! bromine

type(saw_type), parameter, public :: Kr = &
saw_type("krypton", "Kr", 36, &
nan_dp, nan_dp, 83.798_dp, 0.002_dp, &
83.798_dp, 0.002_dp, "g m") !! krypton

type(saw_type), parameter, public :: Rb = &
saw_type("rubidium", "Rb", 37, &
nan_dp, nan_dp, 85.4678_dp, 0.0003_dp, &
85.468_dp, 0.001_dp, "g") !! rubidium

type(saw_type), parameter, public :: Sr = &
saw_type("strontium", "Sr", 38, &
nan_dp, nan_dp, 87.62_dp, 0.01_dp, &
87.62_dp, 0.01_dp, "g r") !! strontium

type(saw_type), parameter, public :: Y = &
saw_type("yttrium", "Y", 39, &
nan_dp, nan_dp, 88.905838_dp, 0.000002_dp, &
88.906_dp, 0.001_dp, "") !! yttrium

type(saw_type), parameter, public :: Zr = &
saw_type("zirconium", "Zr", 40, &
nan_dp, nan_dp, 91.224_dp, 0.002_dp, &
91.224_dp, 0.002_dp, "g") !! zirconium

type(saw_type), parameter, public :: Nb = &
saw_type("nobium", "Nb", 41, &
nan_dp, nan_dp, 92.90637_dp, 0.00001_dp, &
92.906_dp, 0.001_dp, "") !! nobium

type(saw_type), parameter, public :: Mo = &
saw_type("molybdenum", "Mo", 42, &
nan_dp, nan_dp, 95.95_dp, 0.01_dp, &
95.95_dp, 0.01_dp, "g") !! molybdenum

type(saw_type), parameter, public :: Tc = &
saw_type("technetium", "Tc", 43, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! technetium

type(saw_type), parameter, public :: Ru = &
saw_type("ruthenium", "Ru", 44, &
nan_dp, nan_dp, 101.07_dp, 0.02_dp, &
101.07_dp, 0.02_dp, "g") !! ruthenium

type(saw_type), parameter, public :: Rh = &
saw_type("rhodium", "Rh", 45, &
nan_dp, nan_dp, 102.90549_dp, 0.00002_dp, &
102.91_dp, 0.01_dp, "") !! rhodium

type(saw_type), parameter, public :: Pd = &
saw_type("palladium", "Pd", 46, &
nan_dp, nan_dp, 106.42_dp, 0.01_dp, &
106.42_dp, 0.01_dp, "g") !! palladium

type(saw_type), parameter, public :: Ag = &
saw_type("silver", "Ag", 47, &
nan_dp, nan_dp, 107.8682_dp, 0.0002_dp, &
107.87_dp, 0.01_dp, "g") !! silver

type(saw_type), parameter, public :: Cd = &
saw_type("cadmium", "Cd", 48, &
nan_dp, nan_dp, 112.414_dp, 0.004_dp, &
112.41_dp, 0.01_dp, "g") !! cadmium

type(saw_type), parameter, public :: In = &
saw_type("indium", "In", 49, &
nan_dp, nan_dp, 114.818_dp, 0.001_dp, &
114.82_dp, 0.01_dp, "") !! indium

type(saw_type), parameter, public :: Sn = &
saw_type("tin", "Sn", 50, &
nan_dp, nan_dp, 118.70_dp, 0.007_dp, &
118.71_dp, 0.01_dp, "g") !! tin

type(saw_type), parameter, public :: Sb = &
saw_type("antimony", "Sb", 51, &
nan_dp, nan_dp, 121.760_dp, 0.001_dp, &
121.76_dp, 0.01_dp, "g") !! antimony

type(saw_type), parameter, public :: Te = &
saw_type("tellurium", "Te", 52, &
nan_dp, nan_dp, 127.60_dp, 0.03_dp, &
127.60_dp, 0.03_dp, "g") !! tellurium

type(saw_type), parameter, public :: I = &
saw_type("iodine", "I", 53, &
nan_dp, nan_dp, 126.90447_dp, 0.00003_dp, &
126.90_dp, 0.01_dp, "") !! iodine

type(saw_type), parameter, public :: Xe = &
saw_type("xenon", "Xe", 54, &
nan_dp, nan_dp, 131.293_dp, 0.006_dp, &
131.29_dp, 0.01_dp, "g m") !! xenon

type(saw_type), parameter, public :: Cs = &
saw_type("caesium", "Cs", 55, &
nan_dp, nan_dp, 132.90545196_dp, 0.00000006_dp, &
132.91_dp, 0.01_dp, "") !! caesium

type(saw_type), parameter, public :: Ba = &
saw_type("barium", "Ba", 56, &
nan_dp, nan_dp, 137.327_dp, 0.007_dp, &
137.33_dp, 0.01_dp, "") !! barium

type(saw_type), parameter, public :: La = &
saw_type("lanthanum", "La", 57, &
nan_dp, nan_dp, 138.90547_dp, 0.00007_dp, &
138.91_dp, 0.01_dp, "g") !! lanthanum

type(saw_type), parameter, public :: Ce = &
saw_type("cerium", "Ce", 58, &
nan_dp, nan_dp, 140.116_dp, 0.001_dp, &
140.12_dp, 0.01_dp, "g") !! cerium

type(saw_type), parameter, public :: Pr = &
saw_type("praseodymium", "Pr", 59, &
nan_dp, nan_dp, 140.90766_dp, 0.00001_dp, &
140.91_dp, 0.01_dp, "") !! praseodymium

type(saw_type), parameter, public :: Nd = &
saw_type("neodymium", "Nd", 60, &
nan_dp, nan_dp, 144.242_dp, 0.003_dp, &
144.24_dp, 0.01_dp, "g") !! neodymium

type(saw_type), parameter, public :: Pm = &
saw_type("promethium", "Pm", 61, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! promethium

type(saw_type), parameter, public :: Sm = &
saw_type("samarium", "Sm", 62, &
nan_dp, nan_dp, 150.36_dp, 0.02_dp, &
150.36_dp, 0.02_dp, "g") !! samarium

type(saw_type), parameter, public :: Eu = &
saw_type("europium", "Eu", 63, &
nan_dp, nan_dp, 151.964_dp, 0.001_dp, &
151.96_dp, 0.01_dp, "g") !! europium

type(saw_type), parameter, public :: Gd = &
saw_type("gadolinium", "Gd", 64, &
nan_dp, nan_dp, 157.25_dp, 0.03_dp, &
157.25_dp, 0.03_dp, "g") !! gadolinium

type(saw_type), parameter, public :: Tb = &
saw_type("terbium", "Tb", 65, &
nan_dp, nan_dp, 158.925354_dp, 0.000007_dp, &
158.93_dp, 0.01_dp, "") !! terbium

type(saw_type), parameter, public :: Dy = &
saw_type("dysprosium", "Dy", 66, &
nan_dp, nan_dp, 162.500_dp, 0.001_dp, &
162.50_dp, 0.01_dp, "g") !! dysprosium

type(saw_type), parameter, public :: Ho = &
saw_type("holmium", "Ho", 67, &
nan_dp, nan_dp, 164.930329_dp, 0.000005_dp, &
164.93_dp, 0.01_dp, "") !! holmium

type(saw_type), parameter, public :: Er = &
saw_type("erbium", "Er", 68, &
nan_dp, nan_dp, 167.259_dp, 0.003_dp, &
167.26_dp, 0.01_dp, "g") !! erbium

type(saw_type), parameter, public :: Tm = &
saw_type("thulium", "Tm", 69, &
nan_dp, nan_dp, 168.934219_dp, 0.000005_dp, &
168.93_dp, 0.01_dp, "") !! thulium

type(saw_type), parameter, public :: Yb = &
saw_type("ytterbium", "Yb", 70, &
nan_dp, nan_dp, 173.045_dp, 0.010_dp, &
173.05_dp, 0.02_dp, "g") !! ytterbium

type(saw_type), parameter, public :: Lu = &
saw_type("lutetium", "Lu", 71, &
nan_dp, nan_dp, 174.9668_dp, 0.0001_dp, &
174.97_dp, 0.01_dp, "g") !! lutetium

type(saw_type), parameter, public :: Hf = &
saw_type("hafnium", "Hf", 72, &
nan_dp, nan_dp, 178.486_dp, 0.006_dp, &
178.49_dp, 0.01_dp, "g") !! hafnium

type(saw_type), parameter, public :: Ta = &
saw_type("tantalum", "Ta", 73, &
nan_dp, nan_dp, 180.94788_dp, 0.00002_dp, &
180.95_dp, 0.01_dp, "") !! tantalum

type(saw_type), parameter, public :: W = &
saw_type("tungsten", "W", 74, &
nan_dp, nan_dp, 183.84_dp, 0.01_dp, &
183.84_dp, 0.01_dp, "") !! tungsten

type(saw_type), parameter, public :: Re = &
saw_type("rhenium", "Re", 75, &
nan_dp, nan_dp, 186.207_dp, 0.001_dp, &
186.21_dp, 0.01_dp, "") !! rhenium

type(saw_type), parameter, public :: Os = &
saw_type("osmium", "Os", 76, &
nan_dp, nan_dp, 190.23_dp, 0.03_dp, &
190.23_dp, 0.03_dp, "g") !! osmium

type(saw_type), parameter, public :: Ir = &
saw_type("iridium", "Ir", 77, &
nan_dp, nan_dp, 192.217_dp, 0.002_dp, &
192.22_dp, 0.01_dp, "") !! iridium

type(saw_type), parameter, public :: Pt = &
saw_type("platinum", "Pt", 78, &
nan_dp, nan_dp, 195.084_dp, 0.009_dp, &
195.08_dp, 0.02_dp, "") !! platinum

type(saw_type), parameter, public :: Au = &
saw_type("gold", "Au", 79, &
nan_dp, nan_dp, 196.966570_dp, 0.000004_dp, &
196.97_dp, 0.01_dp, "") !! gold

type(saw_type), parameter, public :: Hg = &
saw_type("mercury", "Hg", 80, &
nan_dp, nan_dp, 200.592_dp, 0.003_dp, &
200.59_dp, 0.01_dp, "") !! mercury

type(saw_type), parameter, public :: Tl = &
saw_type("thallium", "Tl", 81, &
204.382_dp, 204.385_dp, 204.3835_dp, 0.0009_dp, &
204.38_dp, 0.01_dp, "") !! thallium

type(saw_type), parameter, public :: Pb = &
saw_type("lead", "Pb", 82, &
206.14_dp, 207.94_dp, 207.0_dp, 0.6_dp, &
207.2_dp, 1.1_dp, "") !! lead

type(saw_type), parameter, public :: Bi = &
saw_type("bismuth", "Bi", 83, &
nan_dp, nan_dp, 208.98040_dp, 0.00001_dp, &
208.98_dp, 0.01_dp, "") !! bismuth

type(saw_type), parameter, public :: Po = &
saw_type("polonium", "Po", 84, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! polonium

type(saw_type), parameter, public :: At = &
saw_type("astatine", "At", 85, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! astatine

type(saw_type), parameter, public :: Rn = &
saw_type("radon", "Rn", 86, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! radon

type(saw_type), parameter, public :: Fr = &
saw_type("francium", "Fr", 87, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! francium

type(saw_type), parameter, public :: Ra = &
saw_type("radium", "Ra", 88, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! radium

type(saw_type), parameter, public :: Ac = &
saw_type("actinium", "Ac", 89, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! actinium

type(saw_type), parameter, public :: Th = &
saw_type("thorium", "Th", 90, &
nan_dp, nan_dp, 232.0377_dp, 0.0004_dp, &
232.04_dp, 0.01_dp, "") !! thorium

type(saw_type), parameter, public :: Pa = &
saw_type("protactinium", "Pa", 91, &
nan_dp, nan_dp, 231.03588_dp, 0.00001_dp, &
231.04_dp, 0.01_dp, "") !! protactinium

type(saw_type), parameter, public :: U = &
saw_type("uranium", "U", 92, &
nan_dp, nan_dp, 238.02891_dp, 0.00003_dp, &
238.03_dp, 0.01_dp, "g m") !! uranium

type(saw_type), parameter, public :: Np = &
saw_type("neptunium", "Np", 93, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! neptunium

type(saw_type), parameter, public :: Pu = &
saw_type("plutonium", "Pu", 94, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! plutonium

type(saw_type), parameter, public :: Am = &
saw_type("americium", "Am", 95, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! americium

type(saw_type), parameter, public :: Cm = &
saw_type("curium", "Cm", 96, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! curium

type(saw_type), parameter, public :: Bk = &
saw_type("berkelium", "Bk", 97, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! berkelium

type(saw_type), parameter, public :: Cf = &
saw_type("californium", "Cf", 98, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! californium

type(saw_type), parameter, public :: Es = &
saw_type("einsteinium", "Es", 99, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! einsteinium

type(saw_type), parameter, public :: Fm = &
saw_type("fermium", "Fm", 100, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! fermium

type(saw_type), parameter, public :: Md = &
saw_type("mendelevium", "Md", 101, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! mendelevium

type(saw_type), parameter, public :: No = &
saw_type("nobelium", "No", 102, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! nobelium

type(saw_type), parameter, public :: Lr = &
saw_type("lawrencium", "Lr", 103, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! lawrencium

type(saw_type), parameter, public :: Rf = &
saw_type("rutherfordium", "Rf", 104, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! rutherfordium

type(saw_type), parameter, public :: Db = &
saw_type("dubnium", "Db", 105, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! dubnium

type(saw_type), parameter, public :: Sg = &
saw_type("seaborgium", "Sg", 106, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! seaborgium

type(saw_type), parameter, public :: Bh = &
saw_type("bohrium", "Bh", 107, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! bohrium

type(saw_type), parameter, public :: Hs = &
saw_type("hassium", "Hs", 108, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! hassium

type(saw_type), parameter, public :: Mt = &
saw_type("meitnerium", "Mt", 109, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! meitnerium

type(saw_type), parameter, public :: Ds = &
saw_type("darmstadtium", "Ds", 110, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! darmstadtium

type(saw_type), parameter, public :: Rg = &
saw_type("roentgenium", "Rg", 111, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! roentgenium

type(saw_type), parameter, public :: Cn = &
saw_type("copernicium", "Cn", 112, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! copernicium

type(saw_type), parameter, public :: Nh = &
saw_type("nihonium", "Nh", 113, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! nihonium

type(saw_type), parameter, public :: Fl = &
saw_type("flerovium", "Fl", 114, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! flerovium

type(saw_type), parameter, public :: Mc = &
saw_type("moscovium", "Mc", 115, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! moscovium

type(saw_type), parameter, public :: Lv = &
saw_type("livermorium", "Lv", 116, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! livermorium

type(saw_type), parameter, public :: Ts = &
saw_type("tennesine", "Ts", 117, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! tennesine

type(saw_type), parameter, public :: Og = &
saw_type("organesson", "Og", 118, &
nan_dp, nan_dp, nan_dp, nan_dp, &
nan_dp, nan_dp, "") !! organesson

end module ciaaw__saw_2021