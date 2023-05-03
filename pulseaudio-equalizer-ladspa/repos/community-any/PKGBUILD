# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=pulseaudio-equalizer-ladspa
pkgver=3.0.2
pkgrel=6
pkgdesc='A 15-band equalizer for PulseAudio'
arch=(any)
url='https://github.com/pulseaudio-equalizer-ladspa/equalizer'
license=('GPL3')
depends=('python-gobject' 'gtk3' 'swh-plugins' 'pulseaudio' 'bc')
makedepends=('meson')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('a916d55f02002de3f0053b0bf1e6f2315e517caa42d6b1e5d19268d895376d990a793d73f52e0050e44b391d61c190c3be23ccf31cef018521740c6cc0a728e0')

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
