# Maintainer: Lukas Jirkovsky <l.jirkovsky@gmail.com>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>

pkgname=intellij-idea-community-edition
pkgver=2018.3.4
_build=183.5429.30
_adt_tools_base_commit=e841aa025aa62a4250040ca2a538daabbff54cf5
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
        idea-adt-tools-base::"git://git.jetbrains.org/idea/adt-tools-base.git#commit=${_adt_tools_base_commit}"
        idea-build.patch
        idea.desktop
        idea.sh)
sha256sums=('db785f692dfc2620035d28016eade34d14f447beb2b69de4c566b0c832e1eb12'
            '408586c688bab9cc9825bfbc4be2504f1ee0f6cc1a7076a9ffba7cdd6a822598'
            'SKIP'
            '9df5bfebad9364899a926ea974a12b7f9924cabf29c504bd944a39bf400cac67'
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
  install -Dm 644 build.txt -t "${pkgdir}"/usr/share/idea
}

# vim: ts=2 sw=2 et:
