# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=6.11.0
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'node-gyp' 'semver')
makedepends=('procps-ng' 'marked-man')
options=('!emptydirs')
source=("$pkgname-$pkgver.tar.gz::https://github.com/npm/cli/archive/v$pkgver.tar.gz")
sha512sums=('cff8c264f219550acd2410326f80ea45f8a079220aea1fb7833c7378774ab5479d5a9ba8fda651d70d89a62f89dba84c422d5c2ecda2d3cdd67b6bf91d542160')

prepare() {
  cd cli-$pkgver
  mkdir -p node_modules/.bin
  ln -sf /usr/bin/marked{,-man} node_modules/.bin/

  mkdir -p man/man1
}

build() {
  cd cli-$pkgver
  make
}

package() {
  cd cli-$pkgver
  make NPMOPTS="--prefix=\"$pkgdir/usr\"" install

  # Non-deterministic race in npm gives 777 permissions to random directories.
  # See https://github.com/npm/npm/issues/9359 for details.
  chmod -R u=rwX,go=rX "$pkgdir"

  # Experimental dedup
  _npmdir="$pkgdir"/usr/lib/node_modules/$pkgname
  rm -r "$_npmdir"/node_modules/{,.bin/}semver
  rm -r "$_npmdir"/node_modules/{,.bin/}node-gyp
  sed -i '/node-gyp.js/c\  exec /usr/bin/node-gyp "$@"' \
    "$_npmdir"/node_modules/npm-lifecycle/node-gyp-bin/node-gyp \
    "$_npmdir"/bin/node-gyp-bin/node-gyp

  install -dm755 "$pkgdir"/usr/share/bash-completion/completions
  node "$srcdir"/cli-$pkgver/bin/npm-cli.js completion > "$pkgdir"/usr/share/bash-completion/completions/npm

  install -Dm644 "$srcdir"/cli-$pkgver/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
