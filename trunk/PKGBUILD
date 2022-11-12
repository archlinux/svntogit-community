# Maintainer: Robin Broda <robin at broda dot me>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=ghidra
pkgver=10.2.1
_d2j=2.0
_yajsw=13.05
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
        https://github.com/pxb1988/dex2jar/releases/download/${_d2j}/dex-tools-${_d2j}.zip
        https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/android4me/AXMLPrinter2.jar
        https://sourceforge.net/projects/yajsw/files/yajsw/yajsw-stable-${_yajsw}/yajsw-stable-${_yajsw}.zip)
noextract=(AXMLPrinter2.jar
           yajsw-beta-${_yajsw}.zip)
sha512sums=('5f06f31d31e73deae1c710ea392258420db196de0240c3a1001a28075edf4afa86a69f6184ca2e24a6555ef53bb6ce6035cfe37c61cd8da3020758b1aa8278fc'
            'SKIP'
            'c4a6c72ea09b58a44fcb8918cfada600467f10f99a02b53d2436ac68295e73c8daf9ba0a8bc7160ba1e28e87f032ee034435ebe40af35b6e2fe9fa4607581358'
            'c1168ec913f1fbb0675915d4fd865ec9a8e8573f6c8aedcb6e68166f61f11aeaececc7548d54d78134843c0102c57d6350973f6d3027d0ffdae52a5c57a7f601'
            'ba6421fcc9d5fd5edf0b5f299914a54a8e3d8cbe79b83cf9b1a4a1828eb26f32f8d04299235233581a848e274665c6d2da9b8394be1d7a824e443efd2508413c')

prepare() {
  export PATH="/usr/lib/jvm/java-17-openjdk/bin:${PATH}"
  cd ghidra-Ghidra_${pkgver}_build

  # Copy needed libraries into flat repo folder
  install -Dm 644 ../dex2jar-${_d2j}/lib/dex-*.jar \
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
