# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=7.0.5
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
        "https://raw.githubusercontent.com/pypa/setuptools_scm/v$pkgver/.git_archival.txt")
sha256sums=('031e13af771d6f892b941adb6ea04545bbf91ebc5ce68c78aaf3fff6e1fb4844'
            'f145442cd29a4a4869c54d82f2e29e3db2e09e65140c6aeb735ef3f7c3077a4e')
b2sums=('242809a32cd23d9d98e3326714d1435220907eacdb3127558987d0d8be95775b7f8ed284707421a9c52e401c1738c11a01782fee2c0635924122307d3308cc0c'
        '204c07543d1c2a552aa2de95549fdef96307f4e8abef274b10685769704606209d52662946ba5883abf09c59ae7dae311936ed852a99e72d41c09f566d8d3ab4')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  ln ../.git_archival.txt test-env/lib/python3.10/site-packages/setuptools_scm
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
