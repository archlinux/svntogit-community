# Maintainer: Lukas Jirkovsky <l.jirkovsky@gmail.com>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>

pkgname=intellij-idea-community-edition
pkgver=2018.2.5
_build=182.4892.20
_adt_tools_base_commit=70a9f8b3756d917717a04140b858a23eef5e60ca
pkgrel=1
epoch=2
pkgdesc='IDE for Java, Groovy and other programming languages with advanced refactoring features'
url='https://www.jetbrains.com/idea/'
arch=('x86_64')
license=('Apache')
backup=('usr/share/idea/bin/idea.vmoptions'
        'usr/share/idea/bin/idea64.vmoptions')
depends=('giflib' 'java-environment=8' 'python' 'sh' 'ttf-font')
makedepends=('apache-ant' 'git' 'java-openjfx')
source=(idea-${_build}.tar.gz::https://github.com/JetBrains/intellij-community/archive/idea/${_build}.tar.gz
        idea-android-${_build}.tar.gz::https://github.com/JetBrains/android/archive/idea/${_build}.tar.gz
        idea-adt-tools-base::"git://git.jetbrains.org/idea/adt-tools-base.git#commit=${_adt_tools_base_commit}"
        idea-build.patch
        idea.desktop
        idea.sh)
sha256sums=('5bf05ce4414a24175106fe3da44ea7915e33f9541733f1484086eeea4446caff'
            '025d3b032a2ec502762465ada12f885415aab9cc09ed816ca56abe36b0f24410'
            'SKIP'
            '3793e8125abb05b1580919017469ada2563a2e5972a8d74666557df60d270cfd'
            'fa9e3cba5e26a7e01cecda867f23467322db123c5553dfbb4f14aae034ccbed7'
            'c021dba82f75a18be6ffdc2fe70d616496bbe3a14e7a5efef30c06b4cbd915c3')

prepare() {
  cd intellij-community-idea-${_build}
  patch -Np1 -i ../idea-build.patch
  echo ${_build} > build.txt
  ln -s "${srcdir}"/android-idea-${_build} android
  ls -lah android/
  ln -s "${srcdir}"/idea-adt-tools-base android/tools-base
}

build() {
  cd intellij-community-idea-${_build}
  unset _JAVA_OPTIONS
  ant build
  tar -xf out/idea-ce/artifacts/ideaIC-${_build}-no-jdk.tar.gz -C "${srcdir}"
}

package() {
  cd idea-IC-${_build}

  # workaround FS#40934
  sed -i 's/lcd/on/' bin/*.vmoptions

  rm -rf bin/fsnotifier{,-arm} lib/libpty/linux/x86

  install -dm 755 "${pkgdir}"/usr/share/{licenses,pixmaps,idea}
  cp -dr --no-preserve='ownership' bin lib plugins redist "${pkgdir}"/usr/share/idea/
  cp -dr --no-preserve='ownership' license "${pkgdir}"/usr/share/licenses/idea
  ln -s /usr/share/idea/bin/idea.png "${pkgdir}"/usr/share/pixmaps/
  install -Dm 644 ../idea.desktop -t "${pkgdir}"/usr/share/applications/
  install -Dm 755 ../idea.sh "${pkgdir}"/usr/bin/idea
}

# vim: ts=2 sw=2 et:
