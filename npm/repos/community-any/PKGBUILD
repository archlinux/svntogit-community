# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=6.12.1
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'node-gyp' 'semver')
makedepends=('procps-ng' 'marked-man')
options=('!emptydirs')
source=("$pkgname-$pkgver.tar.gz::https://github.com/npm/cli/archive/v$pkgver.tar.gz")
sha512sums=('781ad125eebf426714a050eb0d3332c2a22041380c6b5691b6781f49f8324ce8ace7c6040b34ed8132d084da74cb6dfe69a9ef0ccd1c554d86864d13a20f618c')

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

  # npm installs package.json owned by build user
  # https://bugs.archlinux.org/task/63396
  chown -R root:root "$pkgdir"

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
