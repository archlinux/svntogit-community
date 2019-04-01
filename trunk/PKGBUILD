# Maintainer: Lukas Jirkovsky <l.jirkovsky@gmail.com>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>

pkgname=intellij-idea-community-edition
pkgver=2019.1
_build=191.6183.87
pkgrel=1
epoch=2
pkgdesc='IDE for Java, Groovy and other programming languages with advanced refactoring features'
url='https://www.jetbrains.com/idea/'
arch=('x86_64')
license=('Apache')
backup=('usr/share/idea/bin/idea.vmoptions'
        'usr/share/idea/bin/idea64.vmoptions')
depends=('giflib' 'java-environment=8' 'python' 'sh' 'ttf-font' 'libdbusmenu-glib')
makedepends=('ant' 'kotlin' 'git' 'java-openjfx')
source=(idea-${_build}.tar.gz::https://github.com/JetBrains/intellij-community/archive/idea/${_build}.tar.gz
        idea-android-${_build}.tar.gz::https://github.com/JetBrains/android/archive/idea/${_build}.tar.gz
        idea-adt-tools-base::"git://git.jetbrains.org/idea/adt-tools-base.git#tag=idea/${_build}"
        idea-build.patch
        idea.desktop
        idea.sh)
sha256sums=('9162146dbcfb5e44a6bc48f7b71a94ec311a8ccf7972ef7ad029dec00dfe3796'
            '0d5b65f63b77f120c0fbf5d4aad15552b2f60b7faf1a7e471f41e6b9e28f9440'
            'SKIP'
            'd7556a6651ec0c00daa6af3ec205f92945ebae2c5e30d29c04d8f65358e74825'
            'fa9e3cba5e26a7e01cecda867f23467322db123c5553dfbb4f14aae034ccbed7'
            'c021dba82f75a18be6ffdc2fe70d616496bbe3a14e7a5efef30c06b4cbd915c3')

prepare() {
  cd intellij-community-idea-${_build}
  patch -Np1 -i ../idea-build.patch
  echo ${_build} > build.txt
  # build system doesn't like symlinks
  mv "${srcdir}"/android-idea-${_build} android
  mv "${srcdir}"/idea-adt-tools-base android/tools-base
}

build() {
  cd intellij-community-idea-${_build}
  unset _JAVA_OPTIONS
  export JAVA_HOME=/usr/lib/jvm/java-8-openjdk
  export PATH="${JAVA_HOME}/bin:${PATH}"
  ant build
  tar -xf out/idea-ce/artifacts/ideaIC-${_build}-no-jbr.tar.gz -C "${srcdir}"
}

package() {
  cd idea-IC-${_build}

  # workaround FS#40934
  sed -i 's/lcd/on/' bin/*.vmoptions

  rm -rf bin/fsnotifier-arm lib/libpty/linux/x86

  install -dm 755 "${pkgdir}"/usr/share/{licenses,pixmaps,idea,icons/hicolor/scalable/apps}
  cp -dr --no-preserve='ownership' bin lib plugins redist "${pkgdir}"/usr/share/idea/
  cp -dr --no-preserve='ownership' license "${pkgdir}"/usr/share/licenses/idea
  ln -s /usr/share/idea/bin/idea.png "${pkgdir}"/usr/share/pixmaps/
  ln -s /usr/share/idea/bin/idea.svg "${pkgdir}"/usr/share/icons/hicolor/scalable/apps/
  install -Dm 644 ../idea.desktop -t "${pkgdir}"/usr/share/applications/
  install -Dm 755 ../idea.sh "${pkgdir}"/usr/bin/idea
  install -Dm 644 build.txt -t "${pkgdir}"/usr/share/idea
}

# vim: ts=2 sw=2 et:
