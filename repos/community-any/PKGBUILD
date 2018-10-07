# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=pulseaudio-equalizer-ladspa
pkgver=3.0.0
pkgrel=1
pkgdesc='A 15-band equalizer for PulseAudio'
arch=(any)
url='https://github.com/pulseaudio-equalizer-ladspa/equalizer'
license=('GPL3')
depends=('python-gobject' 'gtk3' 'swh-plugins' 'pulseaudio' 'bc')
makedepends=('meson')
optdepends=('python2-gobject: python2 support')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('39d96dae7a40b223ed7b2b637646b78a1167938b9d6af5f8d227ea7b59a941b728c75b33244e7ee1a20655e7be39180add61fe13d9698192f4e27c3f875c189d')

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

