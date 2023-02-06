# Maintainer: Christian Hesse <mail@eworm.de>
# Maintainer: T.J. Townsend <blakkheim@archlinux.org>

pkgname=tmux
pkgver=3.3_a
pkgrel=3
pkgdesc='Terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter' 'systemd-libs')
makedepends=('systemd')
source=("https://github.com/tmux/tmux/releases/download/${pkgver/_/}/tmux-${pkgver/_/}.tar.gz"
        "CVE-2022-47016.patch")
sha256sums=('e4fd347843bd0772c4f48d6dde625b0b109b7a380ff15db21e97c11a4dcdf93f'
            '58fb690833e086b71b52555aa8eced695ace0a0bc51b8bccfda441e35a47ca93')

prepare() {
	cd "$pkgname-${pkgver/_/}"
	patch -Np1 -i ../CVE-2022-47016.patch
}

build() {
	cd "$pkgname-${pkgver/_/}"

	./configure \
		--prefix=/usr \
		--enable-utempter \
		--enable-systemd
	make
}

package() {
	cd "$pkgname-${pkgver/_/}"

	make install DESTDIR="$pkgdir"
	install -D -m0644 COPYING "$pkgdir/usr/share/licenses/tmux/LICENSE"
}
