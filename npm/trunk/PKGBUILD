# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=6.10.3
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'node-gyp' 'semver')
makedepends=('procps-ng' 'marked-man')
options=('!emptydirs')
source=("$pkgname-$pkgver.tar.gz::https://github.com/npm/cli/archive/v$pkgver.tar.gz")
sha512sums=('af173c31c7713c83b083d5be1b75503db24d2228a942c94ee38757b847a15cf309abfe403328239085c93c1f6f42c3859fda4c88b8b80a07cb8d6f8b6b35b7f2')

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
