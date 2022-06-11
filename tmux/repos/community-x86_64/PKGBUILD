# Maintainer: Christian Hesse <mail@eworm.de>

pkgname=tmux
pkgver=3.3_a
pkgrel=2
pkgdesc='A terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter' 'systemd-libs')
makedepends=('systemd')
source=("https://github.com/tmux/tmux/releases/download/${pkgver/_/}/tmux-${pkgver/_/}.tar.gz")
sha256sums=('e4fd347843bd0772c4f48d6dde625b0b109b7a380ff15db21e97c11a4dcdf93f')

build() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	./configure \
		--prefix=/usr \
		--enable-utempter \
		--enable-systemd
	make
}

package() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	make install DESTDIR="$pkgdir"
	install -D -m0644 COPYING "$pkgdir/usr/share/licenses/tmux/LICENSE"
}
