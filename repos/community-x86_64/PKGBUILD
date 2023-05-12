# Maintainer: Robin Broda <robin at broda dot me>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=ghidra
pkgver=10.3
_d2j=2.1
_yajsw=13.09
pkgrel=1
pkgdesc='Software reverse engineering framework'
url='https://ghidra-sre.org/'
arch=('x86_64')
license=('Apache')
depends=('java-environment>=17' 'bash')
makedepends=('git' 'gradle' 'unzip' 'java-environment=17')
optdepends=('pam: GhidraServer support')
options=('!strip')
source=(https://github.com/NationalSecurityAgency/ghidra/archive/Ghidra_${pkgver}_build.tar.gz
        "git+https://github.com/NationalSecurityAgency/ghidra-data#tag=Ghidra_${pkgver}"
        https://github.com/pxb1988/dex2jar/releases/download/v${_d2j}/dex2jar-${_d2j}.zip
        https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/android4me/AXMLPrinter2.jar
        https://sourceforge.net/projects/yajsw/files/yajsw/yajsw-stable-${_yajsw}/yajsw-stable-${_yajsw}.zip)
noextract=(AXMLPrinter2.jar
           yajsw-beta-${_yajsw}.zip)
sha512sums=('79e9130df1274850fc81c9ccbc87f03103dabe992c2a5cde014c24ba9bffe6cc55a09687da91189781ebc81790bdf35828db92b9020cdb6b793462efb345666c'
            'SKIP'
            '44b4a51043ef608158e16f70d9a448ae0a37896da19bd9837e1124e197b7b41a7c37f074386b0cc03edd4f385066bf5ef04c553f6dec0b0cc2a11ecbf299b16f'
            'c1168ec913f1fbb0675915d4fd865ec9a8e8573f6c8aedcb6e68166f61f11aeaececc7548d54d78134843c0102c57d6350973f6d3027d0ffdae52a5c57a7f601'
            'd8682b57ce7577374a17113e1ace77393397e405e6450e3f7637ed1f0f42bc7170b378f775a4ba3c458b202ef35f95b35317cce45659b8a3b25aaa59e8393aa4')

prepare() {
  export PATH="/usr/lib/jvm/java-17-openjdk/bin:${PATH}"
  cd ghidra-Ghidra_${pkgver}_build

  # Copy needed libraries into flat repo folder
  install -Dm 644 ../dex-tools-${_d2j}/lib/dex-*.jar \
    ../AXMLPrinter2.jar \
    -t dependencies/flatRepo

  # YAJSW expects this symlink
  ln -sf ghidra-Ghidra_${pkgver}_build ../ghidra.bin
  install -Dm 644 ../yajsw-stable-${_yajsw}.zip -t dependencies/GhidraServer

  # Add FID datasets
  install -Dm 644 ../ghidra-data/FunctionID/*.fidb -t Ghidra/Features/FunctionID/src/main/fidb

  # Ignore lack of licensing for YAJSW zip, packed FID datasets, and the native binaries
  sed -i '/FileTree tree/a\\t\texclude "yajsw-stable-**.zip"\n\t\texclude "src/main/fidb/**.fidb"\n\t\texclude "os/linux64/**"' gradle/support/ip.gradle
}

build() {
  export GRADLE_HOME="$(pwd)/usr/share/java/gradle/"
  export PATH="$(pwd)/usr/share/java/gradle/bin/:${PATH}"
  cd ghidra-Ghidra_${pkgver}_build
  gradle yajswDevUnpack
  gradle buildNatives_linux_x86_64
  gradle sleighCompile
  gradle buildGhidra
}

package() {
  cd ghidra-Ghidra_${pkgver}_build

  # Extract built archive into destination folder
  install -d "${pkgdir}"/{opt,usr/bin}
  _appver=$(grep -oP '(?<=^application.version=).*$' Ghidra/application.properties)
  _relname=$(grep -oP '(?<=^application.release.name=).*$' Ghidra/application.properties)
  unzip -u "build/dist/ghidra_${_appver}_${_relname}"_*_linux_x86_64.zip -d "${pkgdir}"/opt

  # Simplify some directory and binary names
  mv "${pkgdir}"/opt/ghidra{_*,}
  ln -s /opt/ghidra/ghidraRun "${pkgdir}"/usr/bin/ghidra
  ln -s /opt/ghidra/support/analyzeHeadless "${pkgdir}"/usr/bin/ghidra-analyzeHeadless
}

# vim: ts=2 sw=2 et:
