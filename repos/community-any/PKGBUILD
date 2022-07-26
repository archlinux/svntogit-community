# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=executing
pkgname=python-executing
pkgver=0.9.1
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
sha256sums=('ea278e2cf90cbbacd24f1080dd1f0ac25b71b2e21f50ab439b7ba45dd3195587')
b2sums=('2fe01efab3d6ed268651c5b4b5765bb928d8af7c3674993e321306853cf66c6dbb25c77a167f6236578a0a628dbf4126834bffeb2370f529396759e81a1b51cc')

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
