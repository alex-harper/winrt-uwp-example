#pragma once
#include "SkottiePlayer.g.h"
//#include "skottie/include/Skottie.h"
//#include "skresources/include/SkResources.h"
//#include "include/core/SkCanvas.h"
//#include "include/core/SkFont.h"
//#include "include/core/SkString.h"

namespace winrt::ThermometerWRC::implementation
{
    struct SkottiePlayer : SkottiePlayerT<SkottiePlayer>
    {
        SkottiePlayer() = default;

        hstring LottiePath();
        void LottiePath(hstring const& value);
    };
}
namespace winrt::ThermometerWRC::factory_implementation
{
    struct SkottiePlayer : SkottiePlayerT<SkottiePlayer, implementation::SkottiePlayer>
    {
    };
}
