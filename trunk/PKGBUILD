# Maintainer: Jonas Witschel <diabonas@archlinux.org>
pkgname=luksmeta
pkgver=9
pkgrel=5
pkgdesc='Library for storing metadata in the LUKSv1 header'
arch=('x86_64')
url='https://github.com/latchset/luksmeta'
license=('LGPL')
depends=('cryptsetup' 'libcryptsetup.so')
makedepends=('asciidoc')
source=("$url/releases/download/v$pkgver/$pkgname-$pkgver.tar.bz2"
        "luksmeta_relax-content-tests-in-test-suite.patch::$url/commit/fe3e941a6ed681a7ad1674bf6f6b74e0407bd3fb.patch"
        "luksmeta_force-creation-of-luks1-containers.patch::$url/commit/af81262c0f6e6b37e5c6b520d0fca3a9f9b6c1fc.patch")
sha512sums=('eeecc3de9d621c380d29b2f2ca6ce715f09c20aac8ffc6a3d3cc7dc30c5dc46df686e61928d0accf7e7281ad9baa6ee59a0cf5b58635a311769d8e08c5cc94bd'
            'aeb9d106e432e003b0256164cc644f47b01f347ea25799330e45299a241415b297fd9f2fdd0608c0ad0bc673681a4cb548eeb6e52ded6d2097c0739e6f03748c'
            '47bf756334c76e32dd67720e105ead927693f381efcf23e33af3559510d9db272681a7a47c67da5f122fb0257ddae7185eaa12aea03e6ac9e638d84ac3b101c4')

prepare() {
	cd "$pkgname-$pkgver"
	patch --strip=1 --input="$srcdir/luksmeta_relax-content-tests-in-test-suite.patch"
	patch --strip=1 --input="$srcdir/luksmeta_force-creation-of-luks1-containers.patch"
}

build() {
	cd "$pkgname-$pkgver"
	./configure --prefix=/usr
	make
}

check() {
	cd "$pkgname-$pkgver"
	make check
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
}
