# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=copr-cli
pkgver=1.103
pkgrel=3
pkgdesc="CLI tool to run copr"
url="https://pagure.io/copr/copr"
license=('GPL')
arch=('any')
depends=('python-copr' 'python-humanize' 'python-jinja' 'python-setuptools' 'python-simplejson')
checkdepends=('python-pytest' 'python-responses')
source=("https://pagure.io/copr/copr/archive/copr-cli-$pkgver-1/copr-copr-cli-$pkgver-1.tar.gz")
sha512sums=('8ef4d95c9eb86d8c3521a01919485d52b776a38d09f33bc03035d7fb7c481fecd042bbef8af463dd2e17d54810032efe6934fedd864dd25568fb712e9aaf394d')

build() {
  cd copr-copr-cli-$pkgver-1/cli
  python setup.py build
}

check() {
  cd copr-copr-cli-$pkgver-1/cli
  python -m pytest
}

package() {
  cd copr-copr-cli-$pkgver-1/cli
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 man/*.1 -t "$pkgdir"/usr/share/man/man1/
}
