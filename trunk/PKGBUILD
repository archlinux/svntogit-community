# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Max Liebkies <mail@maxliebkies.de>
# Contributor: Krzysztof Bogacki <krzysztof.bogacki@leancode.pl>

pkgbase=dotnet-core
pkgname=(
 dotnet-host
 dotnet-runtime
 dotnet-sdk
 aspnet-runtime
)
pkgver=3.1.2.sdk102
_runtimever=3.1.2
_sdkver=3.1.102
pkgrel=1
arch=(x86_64)
url=https://www.microsoft.com/net/core
license=(MIT)
makedepends=(
  clang
  cmake
  curl
  git
  icu
  inetutils
  krb5
  libgit2
  libunwind
  lldb
  llvm
  lttng-ust
  openssl
  zlib
)
options=(staticlibs)
source=(
  dotnet-source-build::git+https://github.com/dotnet/source-build.git#tag=e5d3faa5b374e75fea8185a88eee52540c6f2342
  9999-Fix-versionless-RID-computation.patch
  9999-Add-arch-RIDs.patch
)
sha256sums=('SKIP'
            '0e500cd3d1e4a75bf58558020f1b6ad7720f9194dfea2aade7c148af5a031cd7'
            '1d64778c9ac6a5aa49cda743e87ed31ace6aef8aa2e22f98ccd9bb7303cfd593')

prepare() {
  cd dotnet-source-build

  cp ../9999-Fix-versionless-RID-computation.patch patches/core-setup/
  cp ../9999-Add-arch-RIDs.patch patches/corefx/
}

build() {
  cd dotnet-source-build

  export SOURCE_BUILD_SKIP_SUBMODULE_CHECK=1

  ./build.sh
}

package_dotnet-host() {
  pkgdesc='A generic driver for the .NET Core Command Line Interface'
  depends=(glibc)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/usr/{bin,lib,share/{dotnet,licenses/dotnet-host}}
  bsdtar -xf dotnet-sdk-${_sdkver}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner dotnet host
  bsdtar -xf dotnet-sdk-${_sdkver}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/licenses/dotnet-host/ --no-same-owner LICENSE.txt ThirdPartyNotices.txt
  ln -s /usr/share/dotnet/dotnet "${pkgdir}"/usr/bin/dotnet
  ln -s /usr/share/dotnet/host/fxr/${_runtimever}/libhostfxr.so "${pkgdir}"/usr/lib/libhostfxr.so
}

package_dotnet-runtime() {
  pkgdesc='The .NET Core runtime'
  depends=(
    dotnet-host
    glibc
    icu
    krb5
    libcurl.so
    libunwind
    openssl
    zlib
  )

  optdepends=('lttng-ust: CoreCLR tracing')
  provides=(dotnet-runtime-3.1)
  conflicts=(dotnet-runtime-3.1)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${_sdkver}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.NETCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-runtime
}

package_dotnet-sdk() {
  pkgdesc='The .NET Core SDK'
  depends=(
    dotnet-runtime
    glibc
  )
  provides=(dotnet-sdk-3.1)
  conflicts=(dotnet-sdk-3.1)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${_sdkver}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner packs sdk templates
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-sdk
}

package_aspnet-runtime() {
  pkgdesc='The ASP.NET Core runtime'
  depends=(dotnet-runtime)
  provides=(aspnet-runtime-3.1)
  conflicts=(aspnet-runtime-3.1)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/usr/share/{dotnet,licenses}
  bsdtar -xf dotnet-sdk-${_sdkver}-arch-x64.tar.gz -C "${pkgdir}"/usr/share/dotnet/ --no-same-owner shared/Microsoft.AspNetCore.App
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-runtime
}

# vim: ts=2 sw=2 et:
