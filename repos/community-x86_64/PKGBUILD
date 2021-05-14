# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Kristian Mosegaard <kristian@mosen.me>
# Contributor: Max Liebkies <mail@maxliebkies.de>
# Contributor: Krzysztof Bogacki <krzysztof.bogacki@leancode.pl>

pkgbase=dotnet-core
pkgname=(
 dotnet-host
 dotnet-runtime
 aspnet-runtime
 dotnet-sdk
 netstandard-targeting-pack
 dotnet-targeting-pack
 aspnet-targeting-pack
)
pkgver=5.0.6.sdk203
pkgrel=1
arch=(x86_64)
url=https://www.microsoft.com/net/core
license=(MIT)
makedepends=(
  bash
  clang
  cmake
  dotnet-runtime-3.1
  dotnet-sdk
  git
  icu
  inetutils
  krb5
  libgit2
  libunwind
  libxml2
  lldb
  llvm
  lttng-ust
  nodejs
  openssl
  systemd
  zlib
)
options=(staticlibs)
_tag=a8f12771179965da9f48646ded87068d379563b9
source=(
  dotnet-source-build::git+https://github.com/dotnet/source-build.git#tag=${_tag}
  dotnet.sh
  9999-runtime-link-order.patch
  9999-sdk-telemetry-optout.patch
)
b2sums=('SKIP'
        '4a64e3ee550e296bdde894f9202c6f372934cc29154f47d302599b4c368825a96a7b786faa6109a24a1101ff130fd9e4d0ccba094ec91e7f2ca645725bf71b34'
        '437e0b0956576795087f9e5299f6b847aaaef8158847a269d34331d42da6729721d121eed82b95e4833f9d01322da677d85db924bf43140360c5592d51324565'
        '2d69b0eb110f49badbf411ec22be0b10913321275d4146a9e3ea2e5a160a7388e6b0f70200d8ed8640c742f7791694a13be89d85f8424078396ab29e28fca113')

prepare() {
  cp -r /usr/share/dotnet .

  cd dotnet-source-build

  [ -d patches/runtime ] || mkdir patches/runtime
  cp ../9999-runtime-link-order.patch patches/runtime/
  [ -d patches/sdk ] || mkdir patches/sdk
  cp ../9999-sdk-telemetry-optout.patch patches/sdk/

  # disable warnings
  sed -i 's|skiptests|skiptests ignorewarnings|' repos/runtime.common.props
}

pkgver() {
  cd dotnet-source-build

  if [[ $(git describe --tags) != v5.0.*-SDK ]]; then
    exit 1
  fi

  local _runtimever=$(xmllint --xpath "//Dependency[@Name='Microsoft.NETCore.App.Runtime.win-x64']/@Version" eng/Version.Details.xml | cut -d '=' -f 2 | sed 's/^"//; s/"$//')
  local _sdkver=$(xmllint --xpath "//Dependency[@Name='Microsoft.NET.Sdk']/@Version" eng/Version.Details.xml | cut -d '=' -f 2 | sed 's/^"//; s/"$//; s/-rtm.*//; s/-servicing.*//')

  echo "${_runtimever}.sdk${_sdkver##*.}"
}

build() {
  cd dotnet-source-build

  export SOURCE_BUILD_SKIP_SUBMODULE_CHECK=1

  ./build.sh \
    --with-sdk ../dotnet \
    /p:ArchiveDownloadedPackages=true \
    /p:ContinueOnPrebuiltBaselineError=true \
    /p:SkipPortableRuntimeBuild=true \
    /p:SkipPrebuiltEnforcement=true \
    /p:UseSystemLibraries=true \
    /p:UseSystemLibunwind=true
}

package_dotnet-host() {
  pkgdesc='A generic driver for the .NET Core Command Line Interface'
  depends=(
    gcc-libs
    glibc
  )

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/{etc/profile.d,usr/{bin,lib,share/{dotnet,licenses/dotnet-host}}}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner dotnet host
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/licenses/dotnet-host/ --no-same-owner LICENSE.txt ThirdPartyNotices.txt
  ln -s /usr/share/dotnet/dotnet "${pkgdir}"/usr/bin/dotnet
  ln -s /usr/share/dotnet/host/fxr/${pkgver%.sdk*}/libhostfxr.so "${pkgdir}"/usr/lib/libhostfxr.so
  install -Dm 644 "${srcdir}"/dotnet.sh -t "${pkgdir}"/etc/profile.d/
}

package_dotnet-runtime() {
  pkgdesc='The .NET Core runtime'
  depends=(
    dotnet-host
    gcc-libs
    glibc
    icu
    libgssapi_krb5.so
    libunwind
    zlib
    openssl
  )

  optdepends=('lttng-ust: CoreCLR tracing')
  provides=(dotnet-runtime-5.0)
  conflicts=(dotnet-runtime-5.0)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.NETCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-runtime
}

package_aspnet-runtime() {
  pkgdesc='The ASP.NET Core runtime'
  depends=(dotnet-runtime)
  provides=(aspnet-runtime-5.0)
  conflicts=(aspnet-runtime-5.0)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.AspNetCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-runtime
}

package_dotnet-sdk() {
  pkgdesc='The .NET Core SDK'
  depends=(
    dotnet-runtime
    dotnet-targeting-pack
    glibc
    gcc-libs
    netstandard-targeting-pack
  )
  optdepends=('aspnet-targeting-pack: Build ASP.NET Core applications')
  provides=(dotnet-sdk-5.0)
  conflicts=(dotnet-sdk-5.0)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner sdk templates
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-sdk
}

package_netstandard-targeting-pack() {
  pkgdesc='The .NET Standard targeting pack'
  provides=(netstandard-targeting-pack-2.1)
  conflicts=(netstandard-targeting-pack-2.1)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/NETStandard.Library.Ref
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/netstandard-targeting-pack
}

package_dotnet-targeting-pack() {
  pkgdesc='The .NET Core targeting pack'
  depends=(netstandard-targeting-pack)
  provides=(dotnet-targeting-pack-5.0)
  conflicts=(dotnet-targeting-pack-5.0)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.NETCore.App.{Host.arch-x64,Ref}
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-targeting-pack
}

package_aspnet-targeting-pack() {
  pkgdesc='The ASP.NET Core targeting pack'
  depends=(dotnet-targeting-pack)
  provides=(aspnet-targeting-pack-5.0)
  conflicts=(aspnet-targeting-pack-5.0)

  cd dotnet-source-build/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.AspNetCore.App.Ref
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-targeting-pack
}

# vim: ts=2 sw=2 et:
