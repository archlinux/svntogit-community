# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Max Liebkies <mail@maxliebkies.de>

pkgbase=dotnet-core
pkgname=(
 dotnet-host
 dotnet-runtime
 dotnet-sdk
 aspnet-runtime
)
pkgver=2.2.1+102
pkgrel=1
arch=(x86_64)
url='https://www.microsoft.com/net/core'
license=(MIT)
makedepends=(
  clang
  cmake
  curl
  git
  icu
  krb5
  libunwind
  lldb
  llvm
  lttng-ust
  openssl-1.0
  zlib
)
options=(staticlibs)
source=(
  dotnet-source-build::git+https://github.com/dotnet/source-build.git#tag=v${pkgver%+*}-ga
  dotnet-application-insights::git+https://github.com/Microsoft/ApplicationInsights-dotnet.git
  dotnet-aspnet-razor::git+https://github.com/aspnet/Razor.git
  dotnet-cecil::git+https://github.com/mono/cecil.git
  dotnet-cli::git+https://github.com/dotnet/cli.git
  dotnet-cli-migrate::git+https://github.com/dotnet/cli-migrate.git
  dotnet-clicommandlineparser::git+https://github.com/dotnet/clicommandlineparser.git
  dotnet-common::git+https://github.com/aspnet/common.git
  dotnet-core-setup::git+https://github.com/dotnet/core-setup.git
  dotnet-coreclr::git+https://github.com/dotnet/coreclr.git
  dotnet-corefx::git+https://github.com/dotnet/corefx.git
  dotnet-fsharp::git+https://github.com/Microsoft/VisualFSharp.git
  dotnet-linker::git+https://github.com/mono/linker.git
  dotnet-msbuild::git+https://github.com/Microsoft/msbuild.git
  dotnet-newtonsoft-json::git+https://github.com/JamesNK/Newtonsoft.Json.git
  dotnet-nuget-client::git+https://github.com/NuGet/NuGet.Client.git
  dotnet-roslyn::git+https://github.com/dotnet/roslyn.git
  dotnet-roslyn-tools::git+https://github.com/dotnet/roslyn-tools.git
  dotnet-sdk::git+https://github.com/dotnet/sdk.git
  dotnet-standard::git+https://github.com/dotnet/standard.git
  dotnet-templating::git+https://github.com/dotnet/templating.git
  dotnet-vstest::git+https://github.com/Microsoft/vstest.git
  dotnet-websdk::git+https://github.com/aspnet/websdk.git
  dotnet-xliff-tasks::git+https://github.com/dotnet/xliff-tasks.git
  https://download.visualstudio.microsoft.com/download/pr/53cace8f-2907-487e-84d7-bc7a7ba5de05/326704ffa2ef9d4dcd0db2f1da996ebb/aspnetcore-runtime-2.2.1-linux-x64.tar.gz
  dotnet.sh
  dotnet-coreclr-rid.patch
)
sha256sums=('SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            '8a275315b36f6f66038049c34dcb4808e0fa4ece49651957f7be83d6b235f4b8'
            '4978b3a31a94032b425d2a2a9b5a17f506f36fb784fbfefdf2cfea9485a30f47'
            '2c4fc48151e5319d57c8761091709070a17da91eddc2de8a26bc32c60679bfee')

prepare() {
  cd dotnet-source-build

  for submodule in src/{application-insights,aspnet-razor,cli,cli-migrate,clicommandlineparser,common,core-setup,coreclr,corefx,fsharp,linker,msbuild,newtonsoft-json,nuget-client,roslyn,roslyn-tools,sdk,standard,templating,vstest,websdk,xliff-tasks}; do
    git submodule init ${submodule}
    git config submodule.${submodule}.url ../dotnet-${submodule#src/}
    git submodule update
  done

  cd src/linker

  for submodule in cecil; do
    git submodule init ${submodule}
    git config submodule.${submodule}.url ../../../dotnet-${submodule}
    git submodule update
  done

  cd ../coreclr

  patch -Np1 -i "${srcdir}"/dotnet-coreclr-rid.patch
}

build() {
  cd dotnet-source-build

  export PKG_CONFIG_PATH='/usr/lib/openssl-1.0/pkgconfig'
  export SOURCE_BUILD_SKIP_SUBMODULE_CHECK=1

  ./build.sh
}

package_dotnet-host() {
  pkgdesc='A generic driver for the .NET Core Command Line Interface'

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/{opt/dotnet,usr/share/licenses/dotnet-host}
  tar -C "${pkgdir}"/opt/dotnet -xf dotnet-sdk-${pkgver/[0-9]\+}-linux-x64.tar.gz ./dotnet ./host
  tar -C "${pkgdir}"/usr/share/licenses/dotnet-host -xf dotnet-sdk-${pkgver/[0-9]\+}-linux-x64.tar.gz ./LICENSE.txt ./ThirdPartyNotices.txt
  chown root:root -R "${pkgdir}"/opt/dotnet
  install -Dm 755 "${srcdir}"/dotnet.sh "${pkgdir}"/usr/bin/dotnet
}

package_dotnet-runtime() {
  pkgdesc='The .NET Core runtime'
  depends=(
    dotnet-host
    icu
    krb5
    libcurl.so
    libunwind
    openssl-1.0
    zlib
  )
  optdepends=('lttng-ust: CoreCLR tracing')
  provides=(dotnet-runtime-2.2)
  conflicts=(dotnet-runtime-2.2)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/{opt/dotnet,usr/share/licenses}
  tar -C "${pkgdir}"/opt/dotnet -xf dotnet-sdk-${pkgver/[0-9]\+}-linux-x64.tar.gz ./shared
  chown root:root -R "${pkgdir}"/opt/dotnet
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-runtime
}

package_dotnet-sdk() {
  pkgdesc='The .NET Core SDK'
  depends=(dotnet-runtime)
  provides=(dotnet-sdk-2.2)
  conflicts=(dotnet-sdk-2.2)

  cd dotnet-source-build/bin/x64/Release

  install -dm 755 "${pkgdir}"/{opt/dotnet,usr/share/licenses}
  tar -C "${pkgdir}"/opt/dotnet -xf dotnet-sdk-${pkgver/[0-9]\+}-linux-x64.tar.gz ./sdk
  chown root:root -R "${pkgdir}"/opt/dotnet
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/dotnet-sdk
}

package_aspnet-runtime() {
  pkgdesc='The ASP.NET Core runtime'
  depends=(dotnet-runtime)
  provides=(aspnet-runtime-2.2)
  conflicts=(aspnet-runtime-2.2)

  install -dm 755 "${pkgdir}"/{opt/dotnet/shared,usr/share/licenses}
  cp -dr --no-preserve='ownership' shared/Microsoft.AspNetCore.{All,App} "${pkgdir}"/opt/dotnet/shared/
  ln -s dotnet-host "${pkgdir}"/usr/share/licenses/aspnet-runtime
}

# vim: ts=2 sw=2 et:
