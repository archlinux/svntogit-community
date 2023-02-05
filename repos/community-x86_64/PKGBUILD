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
pkgver=7.0.2.sdk102
pkgrel=2
_bootstrapver=7.0.100
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
options=(
  !lto
  staticlibs
)
_tag=4bbdd14480a177e60fba52abf34829020449e46e
source=(
  dotnet-installer::git+https://github.com/dotnet/installer.git#tag=${_tag}
  https://dotnetcli.azureedge.net/source-built-artifacts/assets/Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz
  https://github.com/dotnet/runtime/commit/31e4f404c218eae7ba999c4df5346d30f971451c.patch
  dotnet.sh
)
noextract=(Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz)
b2sums=('SKIP'
        '58b8b56ac1df54c1e1ba059b8dead4ff916c2cd57248e7fd8a5267a665b25e1bd5dad527383d86235c0a42b41908acc84839d8657f092a80d4b84a49240b52b0'
        '36e3dcba3be4d6c3a77cdb92287acaaae681078730d9e94dce3025e926b9691c4439a8b790ca4ece643b8162bdcd7d93d2a3860610841f0b282e8e21c0873446'
        '4a64e3ee550e296bdde894f9202c6f372934cc29154f47d302599b4c368825a96a7b786faa6109a24a1101ff130fd9e4d0ccba094ec91e7f2ca645725bf71b34')

prepare() {
  cd dotnet-installer
  # fix bootstrap
  git remote set-url origin https://github.com/dotnet/installer.git
}

pkgver() {
  cd dotnet-installer

  if [[ $(git describe --tags) != v7.0.* ]]; then
    msg "Invalid SDK version"
    exit 1
  fi

  local _standardver=$(xmllint --xpath "//*[local-name()='NETStandardLibraryRefPackageVersion']/text()" eng/Versions.props)

  if [[ $_standardver != 2.1.0 ]]; then
    msg "Invalid Standard version '$_standardver'"
    exit 1
  fi

  local _newbootstrapver=$(xmllint --xpath "//*[local-name()='PrivateSourceBuiltArtifactsPackageVersion']/text()" eng/Versions.props)

  if [[ $_newbootstrapver != $_bootstrapver ]]; then
    msg "Invalid Bootstrap version '$_newbootstrapver'"
    exit 1
  fi

  local _sdkver=$(xmllint --xpath "//*[local-name()='VersionSDKMinor']/text()" eng/Versions.props)$(xmllint --xpath "//*[local-name()='VersionFeature']/text()" eng/Versions.props)
  local _runtimever=$(xmllint --xpath "//*[local-name()='MicrosoftNETCoreAppRuntimewinx64PackageVersion']/text()" eng/Versions.props)

  echo "${_runtimever}.sdk${_sdkver}"
}

build() {
  export COMPlus_LTTng=0
  export VERBOSE=1
  export OPENSSL_ENABLE_SHA1_SIGNATURES=1

  CFLAGS=$(echo $CFLAGS  | sed -e 's/-fstack-clash-protection//' )
  CXXFLAGS=$(echo $CXXFLAGS  | sed -e 's/-fstack-clash-protection//' )
  export EXTRA_CFLAGS="$CFLAGS"
  export EXTRA_CXXFLAGS="$CXXFLAGS"
  export EXTRA_LDFLAGS="$LDFLAGS"
  unset CFLAGS
  unset CXXFLAGS
  unset LDFLAGS

  cd dotnet-installer

  ./build.sh \
    /p:ArcadeBuildTarball=true \
    /p:TarballDir="${srcdir}"/sources

  cd ../sources

  pushd src/runtime
  sed -i -E 's|( /p:BuildDebPackage=false)|\1 /p:EnablePackageValidation=false|' eng/SourceBuild.props
  sed -i -E 's|( /p:BuildDebPackage=false)|\1 --cmakeargs -DCLR_CMAKE_USE_SYSTEM_LIBUNWIND=TRUE|' eng/SourceBuild.props
  # https://github.com/dotnet/runtime/issues/79196
  patch -Np1 -i "${srcdir}"/31e4f404c218eae7ba999c4df5346d30f971451c.patch
  popd

  ln -sf "${srcdir}"/Private.SourceBuilt.Artifacts.${_bootstrapver}.tar.gz packages/archive/

  ./prep.sh
  ./build.sh \
    -- \
    /v:n \
    /p:ContinueOnPrebuiltBaselineError=true \
    /p:LogVerbosity=n \
    /p:MinimalConsoleLogOutput=false \
    /p:PrebuiltPackagesPath="${srcdir}"/sources/packages \
    /p:SkipPortableRuntimeBuild=true
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
  install -Dm 644 ../../../src/sdk/scripts/register-completions.bash "${pkgdir}"/usr/share/bash-completion/completions/dotnet
  install -Dm 644 ../../../src/sdk/scripts/register-completions.zsh "${pkgdir}"/usr/share/zsh/site-functions/_dotnet
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
  provides=(dotnet-runtime-7.0)
  conflicts=(dotnet-runtime-7.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.NETCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-runtime
}

package_aspnet-runtime() {
  pkgdesc='The ASP.NET Core runtime'
  depends=(dotnet-runtime)
  provides=(aspnet-runtime-7.0)
  conflicts=(aspnet-runtime-7.0)

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
  provides=(dotnet-sdk-7.0)
  conflicts=(dotnet-sdk-7.0)

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
  provides=(dotnet-targeting-pack-7.0)
  conflicts=(dotnet-targeting-pack-7.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.NETCore.App.{Host.arch-x64,Ref}
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-targeting-pack
}

package_aspnet-targeting-pack() {
  pkgdesc='The ASP.NET Core targeting pack'
  depends=(dotnet-targeting-pack)
  provides=(aspnet-targeting-pack-7.0)
  conflicts=(aspnet-targeting-pack-7.0)

  cd sources/artifacts/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${pkgver%.*.sdk*}.${pkgver#*sdk}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs/Microsoft.AspNetCore.App.Ref
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-targeting-pack
}

# vim: ts=2 sw=2 et:
