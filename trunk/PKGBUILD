# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Mario Finelli <mario dot finelli at yahoo dot com>
# Contributor: Andy Weidenbaum <archbaum at gmail dot com>
# Contributor: Peter Wu <lekensteyn at gmail dot com>

pkgname=grunt-cli
pkgver=1.4.3
pkgrel=2
pkgdesc="The grunt command line interface."
arch=('any')
url="https://gruntjs.com/"
license=('MIT')
depends=('nodejs' 'nodejs-nopt')
makedepends=('npm')
source=("https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz"
        "$pkgname-$pkgver.LICENSE::https://github.com/gruntjs/grunt-cli/raw/v$pkgver/LICENSE-MIT")
noextract=($pkgname-$pkgver.tgz)
sha512sums=('f43b71fc0855781e0b633b158828d44247742b0d0c70dda06297661982ad1366b962deefd50f8761955686a5dcfe41a7c6532da8a0f14b0a2d8867859a4ac2a1'
            'e10d81276cacf81f58deca8411a4d3ab0d5213ef4829d755ea0056c0da5ccad600e3b172cdc47949b07b575cf03773f64d9e46b644f99764a051f7f3bca5f903')

package() {
  npm install -g --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  # Non-deterministic race in npm gives 777 permissions to random directories.
  # See https://github.com/npm/npm/issues/9359 for details.
  chmod -R u=rwX,go=rX "$pkgdir"

  # npm installs package.json owned by build user
  # https://bugs.archlinux.org/task/63396
  chown -R root:root "$pkgdir"

  # Experimental dedup
  cd "$pkgdir"/usr/lib/node_modules/$pkgname/node_modules
  for dep in nopt; do
    rm -r $dep;
  done

  # install completions properly
  install -Dm644 "$pkgdir"/usr/lib/node_modules/grunt-cli/completion/bash \
    "$pkgdir"/usr/share/bash-completion/completions/grunt-cli
  install -Dm644 "$pkgdir"/usr/lib/node_modules/grunt-cli/completion/zsh \
    "$pkgdir"/usr/share/zsh/site-functions/_grunt-cli

  install -Dm644 "$srcdir"/$pkgname-$pkgver.LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
