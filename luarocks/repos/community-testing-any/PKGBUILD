# Maintainer: Daurnimator <daurnimator@archlinux.org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Chris Brannon <cmbrannon79@gmail.com>
# Contributor: Geoffroy Carrier <geoffroy@archlinux.org>

pkgname=luarocks
pkgver=3.3.1
pkgrel=2
pkgdesc='Deployment and management system for Lua modules'
backup=(etc/luarocks/config-5.{1,2,3,4}.lua)
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
sha512sums=('0a695ceb30ae575cbca52abd2aad9675e33a234c53c5d1e125442d874c21e0e3cf6157431f07085e4311f81833680366adfe5c626a66cb5880380b48899a116a'
            'SKIP'
            'b34ea6fde901f531f841784c7f75dec3f72ac055333fd1dbafbb2da5f5963b2dd4b89e28d2099e57d201877d0b00ae44bd2aced92ab41ef7a775c8f452985d3a'
            '57378406df3a0454ef46b3b97aaf92bbf2f597ed8216a33757e351efbb151f1fc44ef0ad33f24031eb62f70d3737bf02fb72c3682ea1d533aa9495ca11566ed5'
            '4a24e6f44c13711ba42eab155d7e5699707e9b8d00158104065ce01d8cfdbe5ea9c1e4f12ed10b324caa076b6862a630a4638092827698a5455181e38d821869'
            'b43ccd818c3022b63690b6d060940bbbfd2775b1c174b9e99c8162ea0e746b276b4414c2489156e6bb9eae9ce41d83481022a5a757ea94b62074a6c8c57e9c5a'
            '6b52bd6f446586c3e7d5dbe1ba870e5e37c5bb9cdd5e5878959fa1c151b5a43d8b37c1dc43de46ff2c70c1f57c0429a85c382f53390179609a2880e5aa089497'
            'f6ab6c65aaaa2680ce83a3277a2aec4400d234ddfc17c62f44190928a53b7146c38f8a779aedc1c71fed3dd2f1833e1ca924080e98ecf7462274b0d9acb07f90')
validpgpkeys=('8460980B2B79786DE0C7FCC83FD8F43C2BB3C478')

build() {
  cd "$pkgname-$pkgver"
  ./configure --prefix=/usr
  make ./build/luarocks ./build/luarocks-admin ./build/config-5.4.lua
  make LUA_VERSION=5.1 LUA_INTERPRETER=lua5.1 LUA_INCDIR=/usr/include/lua5.1 ./build/config-5.1.lua
  make LUA_VERSION=5.2 LUA_INTERPRETER=lua5.2 LUA_INCDIR=/usr/include/lua5.2 ./build/config-5.2.lua
  make LUA_VERSION=5.3 LUA_INTERPRETER=lua5.3 LUA_INCDIR=/usr/include/lua5.3 ./build/config-5.3.lua
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
  make DESTDIR="$pkgdir" LUA_VERSION=5.3 install-config
  install -D COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
