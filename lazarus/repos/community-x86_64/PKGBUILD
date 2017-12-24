# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jens Adam <jra@byte.cx>

pkgbase=lazarus
pkgname=('lazarus' 'lazarus-gtk2' 'lazarus-qt4' 'lazarus-qt5')
pkgver=1.8.0
pkgrel=1
url='http://www.lazarus.freepascal.org/'
license=('GPL2' 'MPL' 'custom:modifiedLGPL')
arch=('x86_64')
makedepends=('fpc' 'fpc-src' 'gtk2' 'qt4pas' 'qt5pas' 'rsync')
options=('!emptydirs' '!makeflags')
source=("https://downloads.sourceforge.net/project/lazarus/Lazarus%20Zip%20_%20GZip/Lazarus%20${pkgver}/lazarus-$pkgver.tar.gz")
sha512sums=('dd5e02e9c0a057cf9a6b2c15605969cf4cb743aa78fc81bfdc7c566434127893cf32bab5bd1729f79b51c611bf9ae015bea8d774e0544ead42a064f1224ffd7b')

build() {
  cd "$srcdir"/${pkgbase}

  # build gtk2 ide
  make FPC=/usr/bin/fpc LCL_PLATFORM=gtk2 clean bigide
  # move gtk binaries
  mv lazarus lazarus-gtk2
  mv startlazarus startlazarus-gtk2

  # build qt4 ide
  make FPC=/usr/bin/fpc LCL_PLATFORM=qt bigide
  # move qt binaries
  mv lazarus lazarus-qt4
  mv startlazarus startlazarus-qt4

  # build qt5 ide
  make FPC=/usr/bin/fpc LCL_PLATFORM=qt5 bigide
  # move qt binaries
  mv lazarus lazarus-qt5
  mv startlazarus startlazarus-qt5
}

package_lazarus() {
  pkgdesc='Delphi-like IDE for FreePascal common files'
  depends=('fpc' 'fpc-src')
  optdepends=(
    'perl: to run some scirpts in the tools directory'
    'gtk2: to compile gtk2 apps'
    'qt4pas: to compile qt4 apps and use help viewer'
    'qt5pas: to compile qt5 apps and use help viewer'
  )

  cd "$srcdir"/${pkgbase}

  # skip the 'make install' mess completely and do everything manually
  mkdir -p "$pkgdir"/usr/lib/lazarus "$pkgdir"/usr/bin "$pkgdir"/usr/share/man/man1 "$pkgdir"/usr/share/doc
  rsync -a \
    --exclude="CVS"     --exclude=".cvsignore" \
    --exclude="*.ppw"   --exclude="*.ppl" \
    --exclude="*.ow"    --exclude="*.a"\
    --exclude="*.rst"   --exclude=".#*" \
    --exclude="*.~*"    --exclude="*.bak" \
    --exclude="*.orig"  --exclude="*.rej" \
    --exclude=".xvpics" \
    --exclude="killme*" --exclude=".gdb_hist*" \
    --exclude="debian"  --exclude="COPYING*" \
    --exclude="*.app"   --exclude="tools/install" \
    . "$pkgdir"/usr/lib/lazarus

  #remove some stuff, not needed or for in other package
  pushd "$pkgdir"/usr/lib/lazarus
  rm lazarus-*
  rm startlazarus-*
  popd

  ln -s /usr/lib/lazarus/lazbuild "$pkgdir"/usr/bin/lazbuild
  cp -R install/man/man1/* "$pkgdir"/usr/share/man/man1/
  mv "$pkgdir"/usr/lib/lazarus/docs "$pkgdir"/usr/share/doc/lazarus
  mkdir -p "$pkgdir"/usr/lib/lazarus/docs
  ln -s /usr/share/doc/lazarus/chm "$pkgdir"/usr/lib/lazarus/docs/html
  ln -s /usr/share/doc/lazarus/lazdoc.css "$pkgdir"/usr/lib/lazarus/docs/lazdoc.css

  rm -r "$pkgdir"/usr/lib/lazarus/install

  # license files: /usr/lib/lazarus/COPYING*
  install -D -m644 COPYING.modifiedLGPL.txt "$pkgdir"/usr/share/licenses/$pkgname/COPYING.modifiedLGPL
}

package_lazarus-gtk2() {
  pkgdesc='Delphi-like IDE for FreePascal gtk2 version'
  depends=('lazarus' 'desktop-file-utils' 'gtk2')
  conflicts=('lazarus-qt4' 'lazarus-qt5')

  cd "$srcdir"/${pkgbase}

  # install gtk binaries
  install -Dm755 lazarus-gtk2 "$pkgdir"/usr/lib/lazarus/lazarus
  install -Dm755 startlazarus-gtk2 "$pkgdir"/usr/lib/lazarus/startlazarus
  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/lazarus/lazarus "$pkgdir"/usr/bin/lazarus
  ln -s /usr/lib/lazarus/startlazarus "$pkgdir"/usr/bin/startlazarus

  # make 'desktop-file-validate' happy and fix missing .png icon
  sed -e 's|\(Categories\).*|\1=IDE;Development;|' \
    -e 's|\.png|\.xpm|' -i install/lazarus.desktop
  install -Dm644 install/lazarus.desktop "$pkgdir"/usr/share/applications/lazarus.desktop
  install -Dm644 images/ide_icon48x48.png "$pkgdir"/usr/share/pixmaps/lazarus.png

  # license files: /usr/lib/lazarus/COPYING*
  install -D -m644 COPYING.modifiedLGPL.txt "$pkgdir"/usr/share/licenses/$pkgname/COPYING.modifiedLGPL
}

package_lazarus-qt4() {
  pkgdesc='Delphi-like IDE for FreePascal qt4 version'
  depends=('lazarus' 'qt4pas')
  conflicts=('lazarus-gtk2' 'lazarus-qt5')
  replaces=('lazarus-qt')

  cd "$srcdir"/${pkgbase}

  # install qt binaries
  install -Dm755 lazarus-qt4 "$pkgdir"/usr/lib/lazarus/lazarus
  install -Dm755 startlazarus-qt4 "$pkgdir"/usr/lib/lazarus/startlazarus
  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/lazarus/lazarus "$pkgdir"/usr/bin/lazarus
  ln -s /usr/lib/lazarus/startlazarus "$pkgdir"/usr/bin/startlazarus

  # make 'desktop-file-validate' happy and fix missing .png icon
  sed -e 's|\(Categories\).*|\1=IDE;Development;|' \
    -e 's|\.png|\.xpm|' -i install/lazarus.desktop
  install -Dm644 install/lazarus.desktop "$pkgdir"/usr/share/applications/lazarus.desktop
  install -Dm644 images/ide_icon48x48.png "$pkgdir"/usr/share/pixmaps/lazarus.png

  # license files: /usr/lib/lazarus/COPYING*
  install -D -m644 COPYING.modifiedLGPL.txt "$pkgdir"/usr/share/licenses/$pkgname/COPYING.modifiedLGPL
}

package_lazarus-qt5() {
  pkgdesc='Delphi-like IDE for FreePascal qt5 version'
  depends=('lazarus' 'qt5pas')
  conflicts=('lazarus-gtk2' 'lazarus-qt4')

  cd "$srcdir"/${pkgbase}

  # install qt binaries
  install -Dm755 lazarus-qt5 "$pkgdir"/usr/lib/lazarus/lazarus
  install -Dm755 startlazarus-qt5 "$pkgdir"/usr/lib/lazarus/startlazarus
  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/lazarus/lazarus "$pkgdir"/usr/bin/lazarus
  ln -s /usr/lib/lazarus/startlazarus "$pkgdir"/usr/bin/startlazarus

  # make 'desktop-file-validate' happy and fix missing .png icon
  sed -e 's|\(Categories\).*|\1=IDE;Development;|' \
    -e 's|\.png|\.xpm|' -i install/lazarus.desktop
  install -Dm644 install/lazarus.desktop "$pkgdir"/usr/share/applications/lazarus.desktop
  install -Dm644 images/ide_icon48x48.png "$pkgdir"/usr/share/pixmaps/lazarus.png

  # license files: /usr/lib/lazarus/COPYING*
  install -D -m644 COPYING.modifiedLGPL.txt "$pkgdir"/usr/share/licenses/$pkgname/COPYING.modifiedLGPL
}

# vim:set ts=2 sts=2 sw=2 et:
