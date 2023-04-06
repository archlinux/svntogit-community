# Contributor: Astro Benzene <universebenzene at sina dot com>

_name=sphinxcontrib-jquery
pkgname=python-sphinxcontrib-jquery
pkgver=4.1
pkgrel=2
pkgdesc="Extension to include jQuery on newer Sphinx releases"
arch=('any')
url=https://github.com/sphinx-contrib/jquery
license=('custom:0BSD')
depends=('python-sphinx')
makedepends=('python-build' 'python-flit-core' 'python-installer')
checkdepends=('python-pytest')
provides=('python-sphinxcontrib.jquery')
replaces=('python-sphinxcontrib.jquery')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('1620739f04e36a2c779f1a131a2dfd49b2fd07351bf1968ced074365933abc7a')
b2sums=('3f0ba80c20c13a6543968b0c7234fd86ba238fa723191956e6b125ae709db8a048d585815e6ddb152b3808bcc857bb43c025ffa722a18f74ab265a667c9574b7')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 -t "$pkgdir"/usr/share/doc/$pkgname README.rst
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENCE
}
