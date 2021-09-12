# Maintainer: Lukas Jirkovsky <l.jirkovsky@gmail.com>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Maintainer: Orhun Parmaksız <orhun@archlinux.org>

pkgname=intellij-idea-community-edition
pkgver=2021.2.1
_build=212.5080.55
pkgrel=1
epoch=4
pkgdesc='IDE for Java, Groovy and other programming languages with advanced refactoring features'
url='https://www.jetbrains.com/idea/'
arch=('x86_64')
license=('Apache')
backup=('usr/share/idea/bin/idea.vmoptions'
        'usr/share/idea/bin/idea64.vmoptions')
depends=('giflib' 'java-environment=11' 'python' 'sh' 'ttf-font' 'libdbusmenu-glib' 'fontconfig' 'hicolor-icon-theme')
makedepends=('ant' 'git' 'java-environment=8')
optdepends=(
  'lldb: lldb frontend integration'
)
source=("git+https://github.com/JetBrains/intellij-community.git#tag=idea/${_build}"
        idea-android::"git://git.jetbrains.org/idea/android.git#tag=idea/${_build}"
        idea-adt-tools-base::"git://git.jetbrains.org/idea/adt-tools-base.git#commit=17e9c8b666cac0b974b1efc5e1e4c33404f72904"
        idea.desktop
        idea.sh
        kotlin_dist_for_ide.patch
        skip_jps_build.patch)
sha256sums=('SKIP'
            'SKIP'
            'SKIP'
            '049c4326b6b784da0c698cf62262b591b20abb52e0dcf869f869c0c655f3ce93'
            '115f1091edb138a7a7b15980e8538b4dfd28054cfab38b844df6d918b1b881c5'
            '438be6cb2ee731f6f89ba56506e0fac8aac7136c7dc89d3b4f332351d60d7a1e'
            'b023d7621674f335c32790e25bddadcec483342835af24ab9a3b80d0afc16a0e')

prepare() {
  cd intellij-community

  # build system doesn't like symlinks
  mv "${srcdir}"/idea-android android
  mv "${srcdir}"/idea-adt-tools-base android/tools-base

  # https://youtrack.jetbrains.com/issue/KTIJ-19348
  patch -p0 -i ../kotlin_dist_for_ide.patch

  # https://youtrack.jetbrains.com/issue/IDEA-276102
  # https://youtrack.jetbrains.com/issue/IDEA-277775
  patch -p0 -i ../skip_jps_build.patch

  sed '/def targetOs =/c def targetOs = "linux"' -i build/dependencies/setupJbre.gradle
  sed '/String targetOS/c   String targetOS = OS_LINUX' -i platform/build-scripts/groovy/org/jetbrains/intellij/build/BuildOptions.groovy
  sed -E 's|(<sysproperty key="jna.nosys")|<sysproperty key="intellij.build.target.os" value="linux" />\1|' -i build.xml
  sed -E 's/-Xmx[0-9]+m/-XX:-UseGCOverheadLimit -Didea.home.path=/' -i build.xml
  echo ${_build} > build.txt
}

build() {
  cd intellij-community
  unset _JAVA_OPTIONS
  export JAVA_HOME=/usr/lib/jvm/java-11-openjdk
  export PATH="${JAVA_HOME}/bin:${PATH}"
  export JDK_16_x64=/usr/lib/jvm/java-8-openjdk
  export JDK_18_x64=/usr/lib/jvm/java-8-openjdk
  ant -Dintellij.build.target.os=linux build
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
