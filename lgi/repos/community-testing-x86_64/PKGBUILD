# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: speps <speps at aur dot archlinux dot org>
# Contributor: Sébastien Luttringer

pkgbase=lgi
pkgname=(lua-lgi lua53-lgi)
pkgver=0.9.2
pkgrel=7
pkgdesc='Lua bindings for gnome/gobject using gobject-introspection library'
url="https://github.com/pavouk/$pkgbase"
arch=(x86_64)
license=(MIT)
depends=(glibc glib2 libffi gobject-introspection-runtime)
makedepends=(gobject-introspection lua lua53)
_archive="$pkgbase-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz"
        "$pkgbase-lua54.patch::$url/pull/249.patch")
sha256sums=('cfc4105482b4730b3a40097c9d9e7e35c46df2fb255370bdeb2f45a886548c4f'
            '44d472e96f3645dba786dc62f4a40fb352c6b6fe86d2be888ad181e887d98b31')

prepare() {
	cd "$_archive"
	patch -p1 < ../${source[1]%::*}
	cp -a lgi{,53}
	sed -i Makefile \
		-e '16{p;s/lgi/lgi53/};16i all53 :' \
		-e '28{p;s/lgi/lgi53/};28i install53 :'
}

build() {
	cd "$_archive"
	CFLAGS="$CFLAGS -I/usr/include" make all
	CFLAGS="$CFLAGS -I/usr/include/lua5.3" make all53
}

check() {
	cd "$_archive"
	# TODO: fix cairo-gobject dependency
	# make check
}

package_lua-lgi() {
	depends+=(lua)
	cd "$_archive"
	make \
		LUA_LIBDIR=/usr/lib/lua/5.4 \
		LUA_SHAREDIR=/usr/share/lua/5.4 \
		DESTDIR="$pkgdir/" install
	install -Dm0755 tools/dump-typelib.lua "$pkgdir/usr/bin/dump-typelib"
	install -Dm0644 -t "$pkgdir/usr/share/doc/$pkgname/" README.md docs/*
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname/samples/" samples/*.lua
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname/samples/gtk-demo/" samples/gtk-demo/*
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}

package_lua53-lgi() {
	depends+=(lua53)
	cd "$_archive"
	make \
		LUA_LIBDIR=/usr/lib/lua/5.3 \
		LUA_SHAREDIR=/usr/share/lua/5.3 \
		DESTDIR="$pkgdir/" install53
	# install -Dm0755 tools/dump-typelib.lua "$pkgdir/usr/bin/dump-typelib"
	install -Dm0644 -t "$pkgdir/usr/share/doc/$pkgname/" README.md docs/*
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname/samples/" samples/*.lua
	install -Dm0644 -t "$pkgdir/usr/share/$pkgname/samples/gtk-demo/" samples/gtk-demo/*
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
