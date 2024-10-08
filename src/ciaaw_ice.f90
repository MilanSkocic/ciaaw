module ciaaw__ice
    !! Ciaaw ice - Autogenerated
    !! See [specs](../page/specs/ciaaw_ice.html)
    use ciaaw__common
    use ciaaw__types
    private

type(ice_type), parameter, public :: H_ice = &
ice_type(2,transpose(reshape([&
1.0_dp,0.99984426_dp,5e-8_dp,&
2.0_dp,0.00015574_dp,5e-8_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: He_ice = &
ice_type(2,transpose(reshape([&
3.0_dp,0.000001343_dp,13e-9_dp,&
4.0_dp,0.999998657_dp,13e-9_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Li_ice = &
ice_type(2,transpose(reshape([&
6.0_dp,0.07589_dp,24e-5_dp,&
7.0_dp,0.92411_dp,24e-5_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Be_ice = &
ice_type(1,transpose(reshape([&
9.0_dp,1.00000_dp,0.0000_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: B_ice = &
ice_type(2,transpose(reshape([&
10.0_dp,0.1982_dp,2e-4_dp,&
11.0_dp,0.8018_dp,2e-4_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: C_ice = &
ice_type(2,transpose(reshape([&
12.0_dp,0.988922_dp,28e-6_dp,&
13.0_dp,0.011078_dp,28e-6_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: N_ice = &
ice_type(2,transpose(reshape([&
14.0_dp,0.996337_dp,4e-6_dp,&
15.0_dp,0.003663_dp,4e-6_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: O_ice = &
ice_type(3,transpose(reshape([&
16.0_dp,0.9976206_dp,9e-7_dp,&
17.0_dp,0.0003790_dp,9e-7_dp,&
18.0_dp,0.0020004_dp,5e-7_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: F_ice = &
ice_type(1,transpose(reshape([&
19.0_dp,1.00000_dp,0.0000_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Ne_ice = &
ice_type(3,transpose(reshape([&
20.0_dp,0.904838_dp,90e-6_dp,&
21.0_dp,0.002696_dp,5e-6_dp,&
22.0_dp,0.092465_dp,90e-6_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Na_ice = &
ice_type(1,transpose(reshape([&
23.0_dp,1.00000_dp,0.0000_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Mg_ice = &
ice_type(3,transpose(reshape([&
24.0_dp,0.78951_dp,12e-5_dp,&
25.0_dp,0.10020_dp,8e-5_dp,&
26.0_dp,0.11029_dp,10e-5_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Al_ice = &
ice_type(1,transpose(reshape([&
27.0_dp,1.00000_dp,0.0000_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp,&
-1.0_dp, -1.0_dp, -1.0_dp &
], shape=[3, 10])))

end module ciaaw__ice