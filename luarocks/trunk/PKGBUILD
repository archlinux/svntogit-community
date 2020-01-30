# Maintainer: Daurnimator <daurnimator@archlinux.org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Chris Brannon <cmbrannon79@gmail.com>
# Contributor: Geoffroy Carrier <geoffroy@archlinux.org>

pkgname=luarocks
pkgver=3.3.0
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
source=("https://luarocks.org/releases/$pkgname-$pkgver.tar.gz"{,.asc}
        "luarocks.bash"
        "luarocks.fish"
        "luarocks.zsh"
        "luarocks-admin.bash"
        "luarocks-admin.fish"
        "luarocks-admin.zsh")
md5sums=('202794e8f4945c6085963ecf908ae890'
         'SKIP'
         '781392de1a3b8dc21077165862bbfeec'
         'adfd09f3b8a522675f6954472a1fe72f'
         '2b81640e9d0ae96c7d0e5b145ab69ffc'
         '6001f9e83c8946ac6ef68c6bcbc38348'
         '1c192564378718b918573da36d5589f3'
         '7f9021c0acf9709a2907b5232ef62577')
validpgpkeys=('8460980B2B79786DE0C7FCC83FD8F43C2BB3C478')

build() {
  cd "$pkgname-$pkgver"
  ./configure --prefix=/usr
  make ./build/luarocks ./build/luarocks-admin ./build/config-5.3.lua
  make LUA_VERSION=5.1 LUA_INTERPRETER=lua5.1 LUA_INCDIR=/usr/include/lua5.1 ./build/config-5.1.lua
  make LUA_VERSION=5.2 LUA_INTERPRETER=lua5.2 LUA_INCDIR=/usr/include/lua5.2 ./build/config-5.2.lua
}

package() {
  install -Dm644 luarocks.bash "$pkgdir/usr/share/bash-completion/completions/luarocks"
  install -Dm644 luarocks.fish "$pkgdir/usr/share/fish/vendor_completions.d/luarocks.fish"
  install -Dm644 luarocks.zsh "$pkgdir/usr/share/zsh/site-functions/_luarocks"
  install -Dm644 luarocks-admin.bash "$pkgdir/usr/share/bash-completion/completions/luarocks-admin"
  install -Dm644 luarocks-admin.fish "$pkgdir/usr/share/fish/vendor_completions.d/luarocks-admin.fish"
  install -Dm644 luarocks-admin.zsh "$pkgdir/usr/share/zsh/site-functions/_luarocks-admin"

  cd "$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
  make DESTDIR="$pkgdir" LUA_VERSION=5.1 install-config
  make DESTDIR="$pkgdir" LUA_VERSION=5.2 install-config
  install -D COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
