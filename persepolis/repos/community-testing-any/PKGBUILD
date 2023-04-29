# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: AliReza AmirSamimi <alireza.amirsamimi at gmail dot com>
# Contributor: M A <morealaz at gmail dot com>

pkgname=persepolis
pkgver=3.2.0
pkgrel=8
pkgdesc='Qt front-end for aria2 download manager'
arch=('any')
url='https://persepolisdm.github.io/'
license=('GPL3')
depends=('aria2' 'ffmpeg' 'libnotify' 'libpulse' 'python-psutil' 'python-pyqt5' 'python-requests'
         'python-setproctitle' 'qt5-svg' 'sound-theme-freedesktop' 'youtube-dl')
makedepends=('python-setuptools')
source=("https://github.com/persepolisdm/persepolis/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha256sums=('d27cf2a4e02b0fbe79b1903ca0ab32a6007493d51a8201443a8febb566750acd')

prepare() {
  cd $pkgname-$pkgver
  sed -i 's|/usr/share/pixmaps/|/usr/share/icons/hicolor/scalable/apps/|' setup.py
}

build() {
  cd $pkgname-$pkgver
  python setup.py build
}

package() {
  cd $pkgname-$pkgver 
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}
