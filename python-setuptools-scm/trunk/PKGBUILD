# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=7.1.0
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
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz"
        ".git_archival-$pkgver.txt::https://raw.githubusercontent.com/pypa/setuptools_scm/v$pkgver/.git_archival.txt")
sha256sums=('6c508345a771aad7d56ebff0e70628bf2b0ec7573762be9960214730de278f27'
            'ee1850b42b17c7212741c73c86365815c240c010dbc329d82e8a5e898127ea6d')
b2sums=('be5ae215dadcc290290762b732434258409ecc2d71cdf1332ffe73431effae7cbc33e052a718efd952be79350171ed3e468492fc719bc08750dc23364fb0ee9d'
        '1c977bec059d84c983d25dbb88d848906432d62994960f980adefa9b3057e88aa240b517d262afbc43fd43d50d1e439680af4f832281b550e2c580e1a3308630')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  ln ../.git_archival-$pkgver.txt \
    test-env/lib/python3.10/site-packages/setuptools_scm/.git_archival.txt
  test-env/bin/python -m pytest
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
