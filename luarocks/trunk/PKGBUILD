# Maintainer:  Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Chris Brannon <cmbrannon79@gmail.com>
# Contributor: Geoffroy Carrier <geoffroy@archlinux.org>

pkgbase=luarocks
pkgname=('luarocks' 'luarocks5.1' 'luarocks5.2')
pkgver=3.0.4
pkgrel=1
arch=('any')
url='https://luarocks.org/'
license=('custom')
depends=('unzip' 'zip' 'curl')
makedepends=('lua' 'lua51' 'lua52')
optdepends=('cvs: for fetching sources from CVS repositories'
            'git: for fetching sources from git repositories'
            'mercurial: for fetching sources from mercurial repositories'
            'cmake: for building rocks that use the cmake build system')
options=('!makeflags')
source=(https://luarocks.org/releases/$pkgname-$pkgver.tar.gz{,.asc})
md5sums=('b67be533e0e027a26e3fd2b566ac938f'
         'SKIP')
validpgpkeys=(8460980B2B79786DE0C7FCC83FD8F43C2BB3C478)

prepare() {
  cp -r $pkgbase-$pkgver ${pkgbase}5.1-$pkgver
  cp -r $pkgbase-$pkgver ${pkgbase}5.2-$pkgver
}

build() {

  cd $pkgbase-$pkgver
  LUA_VERSION= ./configure --prefix=/usr \
    --sysconfdir=/etc \
    --lua-version=5.3 \
    --with-lua-include=/usr/include \
    --versioned-rocks-dir
  make

  cd ../${pkgbase}5.1-$pkgver
  ./configure --prefix=/usr \
    --sysconfdir=/etc \
    --lua-version=5.1 \
    --lua-suffix=5.1 \
    --with-lua-include=/usr/include/lua5.1 \
    --versioned-rocks-dir
  make
  sed -i 's/env lua/env lua5.1/' src/bin/luarocks{,-admin}

  cd ../${pkgbase}5.2-$pkgver
  ./configure --prefix=/usr \
    --sysconfdir=/etc \
    --lua-version=5.2 \
    --lua-suffix=5.2 \
    --with-lua-include=/usr/include/lua5.2 \
    --versioned-rocks-dir
  make
  sed -i 's/env lua/env lua5.2/' src/bin/luarocks{,-admin}
}

package_luarocks() {
  pkgdesc='Deployment and management system for Lua 5.3 modules'
  backup=('etc/luarocks/config-5.3.lua')
  depends+=('lua')
  optdepends+=('lua-sec: HTTPS support')

  cd $pkgname-$pkgver
  make install DESTDIR="$pkgdir"
  install -D COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
  cp "$pkgdir"/usr/bin/luarocks{,-5.3}
  cp "$pkgdir"/usr/bin/luarocks-admin{,-5.3}
}

package_luarocks5.1() {
  pkgdesc='Deployment and management system for Lua 5.1 modules'
  backup=('etc/luarocks/config-5.1.lua')
  depends+=('lua51')
  optdepends+=('lua51-sec: HTTPS support')

  cd $pkgname-$pkgver
  make install DESTDIR="$pkgdir"
  install -D COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
  mv "$pkgdir"/usr/bin/luarocks{,-5.1}
  mv "$pkgdir"/usr/bin/luarocks-admin{,-5.1}
}

package_luarocks5.2() {
  pkgdesc='Deployment and management system for Lua 5.2 modules'
  backup=('etc/luarocks/config-5.2.lua')
  depends+=('lua52')
  optdepends+=('lua52-sec: HTTPS support')

  cd $pkgname-$pkgver
  make install DESTDIR="$pkgdir"
  install -D COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
  mv "$pkgdir"/usr/bin/luarocks{,-5.2}
  mv "$pkgdir"/usr/bin/luarocks-admin{,-5.2}
}
