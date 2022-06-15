# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=stack_data
pkgname=python-stack-data
pkgver=0.3.0
pkgrel=1
pkgdesc='Extract data from python stack frames and tracebacks for informative displays'
arch=('any')
url=https://github.com/alexmojaki/stack_data
license=('MIT')
depends=('python-asttokens' 'python-executing' 'python-pure-eval')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('cython' 'python-littleutils' 'python-pygments' 'python-pytest'
              'python-typeguard')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('77bec1402dcd0987e9022326473fdbcc767304892a533ed8c29888dacb7dddbc')
b2sums=('9202ddb2e6e8c8c9e050e085cfe6e1bdbf26124eb85c19516558336d46876aba5ede1b6a87cf17e09c2b44629063a8f5e1f558fdaf64db2db029978a5860cd99')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd "$_name-$pkgver"
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
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

# vim:set ts=2 sw=2 et:
