# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=8.13.2
pkgrel=1
pkgdesc='Enhanced Interactive Python shell'
arch=('any')
url=https://ipython.org
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline' 'python-stack-data')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
# texlive-bin checkdep excluded due to test_latex_to_png_color failure
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy' 'python-trio'
              'python-matplotlib' 'python-curio' 'python-pandas' 'tcsh')
optdepends=('python-black: to auto format with Black'
            'yapf: to auto format with YAPF')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "IPython-icon.png::https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('7dff3fad32b97f6488e02f87b970f309d082f758d7b7fc252e3b19ee0e432dbb'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('dd924954c93eadc844e75cbfe95627f84120a120a7f69a2bd767c8506fe95ddac912ec9e55cad9ed1149369aec699e0e159f02b7a69ea4ec041e4af6677355ee'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $pkgname-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  # FS#47046
  install -Dm644 IPython-icon.png "$pkgdir"/usr/share/pixmaps/ipython.png

  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  cd 'examples/IPython Kernel'
  # FS#45120
  sed -i 's/gnome-netstatus-idle/ipython/' ipython.desktop
  install -Dm644 -t "$pkgdir"/usr/share/applications ipython.desktop

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$pkgname-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
