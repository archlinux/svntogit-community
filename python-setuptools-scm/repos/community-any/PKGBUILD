# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=7.0.4
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-packaging' 'python-setuptools' 'python-tomli'
         'python-typing_extensions')
makedepends=('python-build' 'python-installer' 'python-wheel')
checkdepends=('git' 'mercurial' 'python-pip' 'python-pytest'
              'python-virtualenv')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('c27bc1f48593cfc9527251f1f0fc41ce282ea57bbc7fd5a1ea3acb99325fab4c')
b2sums=('07acfccdbeb0c7f6a6773ff93fa10c35aa8cc2451ede42cce269e2278606fed4acd17e8fda8294ac84b596e776a5ba02ae5ef1203dff42738291798e624cd991')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
 cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  PYTHONPATH="$PWD/test-env/$site_packages"  test-env/bin/python -m pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/setuptools_scm-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
