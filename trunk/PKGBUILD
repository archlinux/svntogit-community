# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=executing
pkgname=python-executing
pkgver=1.1.1
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
sha256sums=('b0d7f8dcc2bac47ce6e39374397e7acecea6fdc380a6d5323e26185d70f38ea8')
b2sums=('cac459eb66650ce8915331fd0f8482dd5bf92cbf9053eefe671ba0e9a6f4ec9c9881c4d998b653390e22ca758dfa2ab2c0e58b33be1190114b8d9dbccb06dcf6')

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
