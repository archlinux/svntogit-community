# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=opensmtpd-filter-senderscore
_pkgname=filter-senderscore
pkgver=0.1.2
pkgrel=1
pkgdesc='OpenSMTPD filter integration for Sender Score'
arch=(i686 x86_64)
url=https://github.com/poolpOrg/filter-senderscore
license=(custom:ISC)
depends=(glibc)
makedepends=(go)
options=('!lto')
source=($pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz)
sha512sums=('92c5e87eb3cd5fdcd1e54e46887ba14e331f665d4edbefc27ce6f0c93f58a60b1e525b696653274cfdd14eaaff4d1e034f92368d5e4a27ecec28ddd951882867')

build() {
	cd "$_pkgname-$pkgver"
	go build -buildmode pie -ldflags "-extldflags $LDFLAGS" -trimpath "$_pkgname.go"
}

package() {
	cd "$_pkgname-$pkgver"

	install -D filter-senderscore -t "$pkgdir"/usr/lib/smtpd/opensmtpd
	install -Dm644 README.md -t "$pkgdir"/usr/share/doc/$pkgname
	install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
