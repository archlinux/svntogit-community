# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=executing
pkgname=python-executing
pkgver=0.9.0
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
sha256sums=('ade7276b4b108df69b8480064264db856335585efe170833601f30bcaaed7bc7')
b2sums=('c0fc2202b65e3c9de274ff0aa8e89fac8c95b40ff3075916f29e5c562ac2fe3e60d135581cb9b09b6281f5772f24eafb52b8bccf7c7b08115922809cc4616721')

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
