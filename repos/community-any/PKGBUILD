# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=8.17.0
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'node-gyp' 'nodejs-nopt' 'semver')
# libgl: TODO
# libvips: for sharp (doc build) (disabled as current version of gatsby imports a broken sharp)
# libxi: for cwebp (doc build)
makedepends=('libgl' 'libxi' 'procps-ng' 'python')
options=('!emptydirs')
source=("https://github.com/npm/cli/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('9c6d8d0aed2f0e7220968f0884eaf9fd1f3aeda38693e78f26f86bd139ea81e808e5b74c63b4f693f572fe43ebc7f0f193a10c182f835c774dd7971186f3dce4')

prepare() {
  cd cli-$pkgver
  # 'deps' was added as a dep for many Makefile targets since 8.6 but it's not easy to fix.
  # Let's skip and do it ourselves instead.
  sed -i 's|node bin/npm-cli.js run resetdeps|true|' Makefile
}

build() {
  cd cli-$pkgver
  node . i --ignore-scripts --no-audit --no-fund
  NODE_PATH=/usr/lib/node_modules make
}

package() {
  cd cli-$pkgver
  node bin/npm-cli.js install -g -f --prefix="$pkgdir/usr" $(node bin/npm-cli.js pack | tail -1)

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
  rm -r "$_npmdir"/node_modules/{,.bin/}nopt
  sed -i 's|../../node_modules/node-gyp/bin/node-gyp.js|../../../node-gyp/bin/node-gyp.js|' \
    "$_npmdir"/bin/node-gyp-bin/node-gyp

  install -dm755 "$pkgdir"/usr/share/bash-completion/completions
  node "$srcdir"/cli-$pkgver/bin/npm-cli.js completion > "$pkgdir"/usr/share/bash-completion/completions/npm

  mv "$pkgdir"/usr/lib/node_modules/npm/man "$pkgdir"/usr/share/

  install -Dm644 "$srcdir"/cli-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
