# Maintainer: Tim Meusel <tim@bastelfreak.de>
# Contributor: Jonathan Steel <jsteel at archlinux.org>
# Contributor: Greg Sutcliffe <greg.sutcliffe@gmail.com>>

pkgname=ruby-shadow
pkgver=2.5.1
pkgrel=1
pkgdesc="Shadow password module"
arch=('x86_64')
url="https://github.com/apalmblad/${pkgname}"
license=('Unlicense')
depends=('ruby')
source=($pkgname-$pkgver.tar.gz::https://github.com/apalmblad/$pkgname/archive/$pkgver.tar.gz)
sha512sums=('04b73809fe2615b2a4b34b8e08ddce032fc5d7e6d55a93162424db9067e7b7bcb46fb48156ba4cc346a9f8bd0bc54163cdbbdeedb64f43b473269e6bf9e606af')

prepare() {
  cd "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"

  ruby extconf.rb
  make
}

package() {
  cd "${pkgname}-${pkgver}"

  make DESTDIR="$pkgdir"/ sitedir='$(rubylibprefix)/vendor_ruby' sitehdrdir='$(rubyhdrdir)/vendor_ruby' install

  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
