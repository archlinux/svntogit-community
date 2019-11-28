# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer:  TDY <tdy@gmx.com>
# Contributor: Grigorios Bouzakis <grbzks[at]gmail[dot]com>

pkgname=tmux
pkgver=3.0
pkgrel=2
pkgdesc='A terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter')
source=("https://github.com/tmux/tmux/releases/download/${pkgver/_/}/tmux-${pkgver/_/}.tar.gz"
        '0001-fixes.patch'
        'LICENSE')
sha256sums=('9edcd78df80962ee2e6471a8f647602be5ded62bb41c574172bb3dc3d0b9b4b4'
            'dbcadb45a934c80164dd52ca2fb5f55f9adb79169a849c04f00446c07754cff4'
            'b5de80619e4884ced2dfe0a96020e85dcfb715a831ecdfdd7ce8c97b5a6ff2cc')

prepare() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	patch -Np1 < ../0001-fixes.patch
}

build() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	./configure \
		--prefix=/usr \
		--enable-utempter
	make
}

package() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	make install DESTDIR="$pkgdir"
	install -Dm644 "$srcdir"/LICENSE "$pkgdir/usr/share/licenses/tmux/LICENSE"
}
