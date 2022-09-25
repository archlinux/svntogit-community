# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=executing
pkgname=python-executing
pkgver=1.1.0
pkgrel=1
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/alexmojaki/executing
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-asttokens' 'python-littleutils' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('2c2c07d1ec4b2d8f9676b25170f1d8445c0ee2eb78901afb075a4b8d83608c6a')
b2sums=('3c44e2f1c26a1a37c1d5669f24f635a07ec220d055bb7bbbbbd0eb82371f30551306be385c54759069c36c440b89a5ef665bfc0cacea63da73117e176955133c')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd "$_name-$pkgver"
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python tests/test_main.py
  test-env/bin/python -m pytest tests/test_pytest.py
}

package() {
  cd "$_name-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE.txt \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}
