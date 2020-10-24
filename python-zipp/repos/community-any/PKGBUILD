# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.3.2
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-jaraco' 'python-func-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('86746c9c1e005fc6235fc4580a99a4f8d663e2c2b495e0f864a39cf58f016359dfe468aa3b189f80c8b631f9b4f9b2fa69677165a76a6974d545835c82df205b')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python setup.py build
}

check() {
  cd zipp-$pkgver
  python -m unittest discover
}

package() {
  cd zipp-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
