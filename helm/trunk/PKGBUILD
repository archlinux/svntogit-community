# Maintainer: David Runge <dave@sleepmap.de>
pkgname=helm
pkgver=0.9.0
pkgrel=5
pkgdesc="A cross-platform, polyphonic synthesizer, available standalone and as an LV2 plugin"
arch=('x86_64')
url="http://tytel.org/helm/"
license=('GPL')
groups=('pro-audio' 'lv2-plugins')
depends=('alsa-lib' 'curl' 'freetype2' 'hicolor-icon-theme' 'libxinerama' 'lv2' 'mesa')
makedepends=('jack' 'libxcursor')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/mtytel/${pkgname}/archive/v${pkgver}.tar.gz")
sha512sums=('241c6bf3aec422e9ccaf7c7113eec7e30a11baadd30fe8f05f0abfac9c41d0c8a9fb284f0cae49bcaf0d3d08aa952737f6ff3eb7d48c2b2e22c60932738aeaa4')

prepare() {
  cd "${pkgname}-${pkgver}"
  sed -e 's/JUCE_INCLUDE_PNGLIB_CODE=0/JUCE_INCLUDE_PNGLIB_CODE=1/g' \
    -i {standalone/builds/linux,builds/linux/{VST,LV2}}/Makefile
}

build() {
  cd "${pkgname}-${pkgver}"
  make PREFIX="/usr" standalone lv2
}

package() {
  cd "${pkgname}-${pkgver}"
  make DESTDIR="$pkgdir/" install_standalone install_lv2
}
