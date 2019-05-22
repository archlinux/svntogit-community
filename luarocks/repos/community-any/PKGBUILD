# Maintainer: Daurnimator <daurnimator@archlinux.org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Chris Brannon <cmbrannon79@gmail.com>
# Contributor: Geoffroy Carrier <geoffroy@archlinux.org>

pkgname=luarocks
pkgver=3.1.2
pkgrel=1
pkgdesc='Deployment and management system for Lua modules'
backup=(etc/luarocks/config-5.{1,2,3}.lua)
arch=('any')
url='https://luarocks.org/'
license=('custom')
replaces=('luarocks5.1' 'luarocks5.2')
depends=('coreutils' # need chmod, md5sum
         'curl' # need one of curl or wget
         'lua'
         'unzip' # need unzip and zip or lua-zlib
         'zip')
optdepends=('cvs: for fetching sources from CVS repositories'
            'git: for fetching sources from git repositories'
            'mercurial: for fetching sources from mercurial repositories'
            'cmake: for building rocks that use the cmake build system'
            'lua-sec: HTTPS support')
source=("https://luarocks.org/releases/$pkgname-$pkgver.tar.gz"{,.asc})
md5sums=('8cde5e602b9f5fc727a59aa44c194ee6'
         'SKIP')
validpgpkeys=('8460980B2B79786DE0C7FCC83FD8F43C2BB3C478')

build() {
  cd "$pkgname-$pkgver"
  ./configure --prefix=/usr
  make ./build/luarocks ./build/luarocks-admin ./build/config-5.3.lua
  make LUA_VERSION=5.1 LUA_INTERPRETER=lua5.1 LUA_INCDIR=/usr/include/lua5.1 ./build/config-5.1.lua
  make LUA_VERSION=5.2 LUA_INTERPRETER=lua5.2 LUA_INCDIR=/usr/include/lua5.2 ./build/config-5.2.lua
}

package() {
  cd "$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
  make DESTDIR="$pkgdir" LUA_VERSION=5.1 install-config
  make DESTDIR="$pkgdir" LUA_VERSION=5.2 install-config
  install -D COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
