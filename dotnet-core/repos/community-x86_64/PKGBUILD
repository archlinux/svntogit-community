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
pkgver=6.0.0.sdk100
pkgrel=2
_bootstrapver=0.1.0-6.0.100-bootstrap.29
arch=(x86_64)
url=https://www.microsoft.com/net/core
license=(MIT)
makedepends=(
  bash
  clang
  cmake
  git
  icu
  inetutils
  krb5
  libgit2
  libunwind
  libxml2
  lldb
  llvm
  lttng-ust2.12
  nodejs
  openssl
  systemd
  zlib
)
optdepends=('bash-completion: Bash completion support')
options=(staticlibs)
_tag=9e8b04bbff820c93c142f99a507a46b976f5c14c
source=(
  dotnet-installer::git+https://github.com/dotnet/installer.git#tag=${_tag}
  https://dotnetcli.azureedge.net/source-built-artifacts/assets/Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz
  dotnet.sh
  dotnet-core-runtime-disable-package-validation.patch
  dotnet-core-sdk-telemetry-optout.patch
)
noextract=(Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz)
b2sums=('SKIP'
        'a0171c3a8acdb3f5c56359e274984081f5e2c54bd02df677987dc57711e856ccde9266a739bc7db4b17da3ff7f922a3370a23d2be2e5d92e9ebf17c016c2e6e7'
        '4a64e3ee550e296bdde894f9202c6f372934cc29154f47d302599b4c368825a96a7b786faa6109a24a1101ff130fd9e4d0ccba094ec91e7f2ca645725bf71b34'
        'b9472b3967c9d7549ee2bbf0180d919748b40b1f9a65b1c3789be40f62ed17a9d37c2020409f7835570620108bd5ec43e728966d075d66bf0b7261cdd36a60c3'
        '95b083b842da6049a084ca015b7ddc099550aa818fc382d556cca832fee52265be568d20a2c50e70819aef6cf879e7a368f7dd3b5966356643b2efdd756e73f4')

prepare() {
  cd dotnet-installer
  # fix bootstrap
  git remote set-url origin https://github.com/dotnet/installer.git
}

pkgver() {
  cd dotnet-installer

  if [[ $(git describe --tags) != v6.0.* ]]; then
    echo "Invalid SDK version"
    exit 1
  fi

  local _standardver=$(xmllint --xpath "//*[local-name()='NETStandardLibraryRefPackageVersion']/text()" eng/Versions.props)

  if [[ $_standardver != 2.1.0 ]]; then
    echo "Invalid Standard version"
    exit 1
  fi

  local _sdkver=$(xmllint --xpath "//*[local-name()='VersionSDKMinor']/text()" eng/Versions.props)$(xmllint --xpath "//*[local-name()='VersionFeature']/text()" eng/Versions.props)
  local _runtimever=$(xmllint --xpath "//*[local-name()='MicrosoftNETCoreAppRuntimewinx64PackageVersion']/text()" eng/Versions.props)


  echo "${_runtimever}.sdk${_sdkver}"
}

build() {
  cd dotnet-installer
  ./build.sh \
    /p:ArcadeBuildTarball=true \
    /p:TarballDir="${srcdir}"/sources
  cd ../sources
  pushd src/runtime.*
  patch -Np1 -i ../../../dotnet-core-runtime-disable-package-validation.patch
  popd
  pushd src/sdk.*
  patch -Np1 -i ../../../dotnet-core-sdk-telemetry-optout.patch
  popd
  ln -sf "${srcdir}"/Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz packages/archive/
  ./prep.sh
  ./build.sh
}

package_dotnet-host() {
  pkgdesc='A generic driver for the .NET Core Command Line Interface'
  depends=(
    gcc-libs
    glibc
  )
  optdepends=('bash-completion: Bash completion support')

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/{etc/profile.d,usr/{bin,lib,share/{dotnet,licenses/dotnet-host}}}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner dotnet host
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/licenses/dotnet-host/ --no-same-owner LICENSE.txt ThirdPartyNotices.txt
  ln -s /usr/share/dotnet/dotnet "${pkgdir}"/usr/bin/dotnet
  ln -s /usr/share/dotnet/host/fxr/${pkgver%.sdk*}/libhostfxr.so "${pkgdir}"/usr/lib/libhostfxr.so
  install -Dm 644 ../../../src/sdk.*/scripts/register-completions.bash "${pkgdir}"/usr/share/bash-completion/completions/dotnet
  install -Dm 644 ../../../src/sdk.*/scripts/register-completions.zsh "${pkgdir}"/usr/share/zsh/site-functions/_dotnet
  install -Dm 644 ../../../../dotnet.sh -t "${pkgdir}"/etc/profile.d/
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

  optdepends=('lttng-ust2.12: CoreCLR tracing')
  provides=(dotnet-runtime-6.0)
  conflicts=(dotnet-runtime-6.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.NETCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-runtime
}

package_aspnet-runtime() {
  pkgdesc='The ASP.NET Core runtime'
  depends=(dotnet-runtime)
  provides=(aspnet-runtime-6.0)
  conflicts=(aspnet-runtime-6.0)

  cd sources/artifacts/x64/Release

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
  provides=(dotnet-sdk-6.0)
  conflicts=(dotnet-sdk-6.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner sdk sdk-manifests templates
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-sdk
}

package_netstandard-targeting-pack() {
  pkgdesc='The .NET Standard targeting pack'
  provides=(netstandard-targeting-pack-2.1)
  conflicts=(netstandard-targeting-pack-2.1)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/NETStandard.Library.Ref
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/netstandard-targeting-pack
}

package_dotnet-targeting-pack() {
  pkgdesc='The .NET Core targeting pack'
  depends=(netstandard-targeting-pack)
  provides=(dotnet-targeting-pack-6.0)
  conflicts=(dotnet-targeting-pack-6.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.NETCore.App.{Host.arch-x64,Ref}
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-targeting-pack
}

package_aspnet-targeting-pack() {
  pkgdesc='The ASP.NET Core targeting pack'
  depends=(dotnet-targeting-pack)
  provides=(aspnet-targeting-pack-6.0)
  conflicts=(aspnet-targeting-pack-6.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.AspNetCore.App.Ref
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-targeting-pack
}

# vim: ts=2 sw=2 et:
