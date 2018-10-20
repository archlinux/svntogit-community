# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=pulseaudio-equalizer-ladspa
pkgver=3.0.1
pkgrel=1
pkgdesc='A 15-band equalizer for PulseAudio'
arch=(any)
url='https://github.com/pulseaudio-equalizer-ladspa/equalizer'
license=('GPL3')
depends=('python-gobject' 'gtk3' 'swh-plugins' 'pulseaudio' 'bc')
makedepends=('meson')
optdepends=('python2-gobject: python2 support')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('377a7aeff31ffe9cf3d5e10325b23177a5c3e5fcaeae506c9d59a93a781756311b2811557d3e9b5df4db4dc4d4aa09ccfb3a424baf6d102852574bdd4d49d570')

build() {
  mkdir -p equalizer-$pkgver/build
  cd equalizer-$pkgver/build

  arch-meson ..

  ninja
}

package() {
  cd equalizer-$pkgver/build

  DESTDIR="$pkgdir" meson install

  python -m compileall -d /usr/lib "$pkgdir"/usr/lib
  python -O -m compileall -d /usr/lib "$pkgdir"/usr/lib

  # It's GLP3 but has a specific copyright string
  install -Dm 644 ../LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

