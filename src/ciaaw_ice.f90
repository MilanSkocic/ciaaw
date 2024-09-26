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
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: He_ice = &
ice_type(2,transpose(reshape([&
3.0_dp,0.000001343_dp,13e-9_dp,&
4.0_dp,0.999998657_dp,13e-9_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Li_ice = &
ice_type(2,transpose(reshape([&
6.0_dp,0.07589_dp,24e-5_dp,&
7.0_dp,0.92411_dp,24e-5_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: Be_ice = &
ice_type(1,transpose(reshape([&
9.0_dp,1.00000_dp,0.0000_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp &
], shape=[3, 10])))

type(ice_type), parameter, public :: B_ice = &
ice_type(2,transpose(reshape([&
10.0_dp,0.1982_dp,2e-4_dp,&
11.0_dp,0.8018_dp,2e-4_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp,&
nan_dp, nan_dp, nan_dp &
], shape=[3, 10])))

end module ciaaw__ice