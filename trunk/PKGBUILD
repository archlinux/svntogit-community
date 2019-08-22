# Maintainer: Lukas Jirkovsky <l.jirkovsky@gmail.com>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>

pkgname=intellij-idea-community-edition
pkgver=2019.2.1
_build=192.6262.58
pkgrel=1
epoch=2
pkgdesc='IDE for Java, Groovy and other programming languages with advanced refactoring features'
url='https://www.jetbrains.com/idea/'
arch=('x86_64')
license=('Apache')
backup=('usr/share/idea/bin/idea.vmoptions'
        'usr/share/idea/bin/idea64.vmoptions')
depends=('giflib' 'java-environment=11' 'python' 'sh' 'ttf-font' 'libdbusmenu-glib')
makedepends=('ant' 'kotlin' 'git' 'java8-openjfx' 'java-environment=8')
source=(idea-${_build}.tar.gz::https://github.com/JetBrains/intellij-community/archive/idea/${_build}.tar.gz
        idea-android-${_build}.tar.gz::https://github.com/JetBrains/android/archive/idea/${_build}.tar.gz
        idea-adt-tools-base::"git://git.jetbrains.org/idea/adt-tools-base.git#tag=idea/${_build}"
        idea-build.patch
        idea.desktop
        idea.sh)
sha256sums=('fbf31030d64090a616a6641556817f409593a21fbb4a7aa1748ddc81526d8000'
            '06e201a2f83f9cc542a840e7582e09c316117147bbea95a938cbe98441d42177'
            'SKIP'
            '6a94352edfcf7426679d124dfc93395a82e6f14f5910dde7f1ff931781c0c543'
            'fa9e3cba5e26a7e01cecda867f23467322db123c5553dfbb4f14aae034ccbed7'
            '5d4f998bec3249165b0e62b5e51e9b7fbe383bb9f1178ffefe070f2c9872eebb')

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
