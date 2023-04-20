# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Marcel Campello <marcel.campello@prafrentex.com.br>
# Contributor: David Birks <david@birks.dev>

pkgname=aws-cli-v2
pkgver=2.11.14
pkgrel=2
pkgdesc='Unified command line interface for Amazon Web Services (version 2)'
arch=(any)
url='https://github.com/aws/aws-cli/tree/v2'
license=(Apache)
depends=(python python-awscrt python-certifi python-colorama python-cryptography python-dateutil
         python-distro python-docutils python-jmespath python-prompt_toolkit python-ruamel-yaml
         python-urllib3)
makedepends=(python-build python-wheel python-flit-core python-installer)
# Tests need the 'ps' binary
checkdepends=(python-pytest python-pytest-xdist python-jsonschema python-mock procps-ng)
provides=(aws-cli)
conflicts=(aws-cli)
source=("https://awscli.amazonaws.com/awscli-$pkgver.tar.gz"{,.sig}
        build-ac.index-in-tmp.diff
        fix-env.diff
        "$pkgname-tz-fix.patch::https://github.com/aws/aws-cli/pull/7762.patch")
sha256sums=('7adbfc53585f1587cce05850b931113921ae74c1deb30dcaf5b3c4c40c9208c7'
            'SKIP'
            '0267e41561ab2c46a97ebfb024f0b047aabc9e6b9866f204b2c1a84ee5810d63'
            '893d61d7e958c3c02bfa1e03bf58f6f6abd98849d248cc661f1c56423df9f312'
            '4fc614b8550d7363bb2d578c6b49326c9255203eb2f933fd0551f96ed5fb1f30')
validpgpkeys=(
  'FB5DB77FD5C118B80511ADA8A6310ACC4672475C'  # the key mentioned on https://docs.aws.amazon.com/cli/latest/userguide/getting-started-install.html
)

prepare() {
  cd awscli-$pkgver

  # Don't treat warnings as errors
  sed -i '/"error::/d' pyproject.toml

  # ac.index is an SQLite database, and building it on copy-on-write filesystems (ex: BTRFS) takes ages
  patch -Np1 -i ../build-ac.index-in-tmp.diff

  # Fix conflicts between tests/functional/test_clidriver.py::TestSession and tests/functional/botocore/leak/test_resource_leaks.py
  patch -Np1 -i ../fix-env.diff

  # Fix possible test failure with a non-UTC time zone (https://bugs.archlinux.org/task/77919)
  patch -Np1 -i ../$pkgname-tz-fix.patch
}

build() {
  cd awscli-$pkgver

  # flit-core adds runtime dependencies to reported build-time dependencies [1],
  # and upstream often lags behind the latest dependencies [2], thus --skip-dependency-check
  # [1] https://github.com/pypa/flit/issues/354
  # [2] https://github.com/aws/aws-cli/issues/5943
  python -m build --wheel --no-isolation --skip-dependency-check
  # Copy the built ac.index for tests
  cp -v build/unpacked_wheel/awscli/data/ac.index awscli/data/ac.index
}

check() {
  cd awscli-$pkgver

  export AWS_SECRET_ACCESS_KEY=fake_key
  export AWS_ACCESS_KEY_ID=fake_id

  export PYTHONPATH="$PWD"

  # * Use --dist=loadfile following upstream. The default --dist=load may cause test failures and is not faster
  # * Disable backend tests - those tests check if aws-cli can be installed or not, and are not compatible with all kinds of environments
  pytest tests -n auto --dist loadfile --ignore=tests/backends --ignore=tests/integration
}

package() {
  cd awscli-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm 644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm 644 bin/aws_bash_completer "$pkgdir/usr/share/bash-completion/completions/aws"
}
